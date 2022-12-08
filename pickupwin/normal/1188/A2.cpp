#include <cstdio>
#include <algorithm>

using std::swap;

const int MAXN=1011;

int N;

struct Vert{
	int FE;
	int Deg;
} V[MAXN];

struct Edge{
	int y, next, v;
} E[MAXN<<1];

int Ecnt;

void addE(int a, int b, int c){
	++Ecnt;
	E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;E[Ecnt].v=c;
}

int Fetch_1(int at, int f){
	for(int k=V[at].FE, to;k;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		return Fetch_1(to, at);
	}
	return at;
}

void Fetch_2(int at, int f, int &r1, int &r2){
	int c=0;
	for(int k=V[at].FE, to;k && c<2;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		++c;
		if(c==1)	r1=Fetch_1(to, at);
		if(c==2)	r2=Fetch_1(to, at);
	}
}

struct Move{
	int a, b, c;
	void show(){
		printf("%d %d %d\n", a, b, c);
	}
} Mo[MAXN<<4];

int Mc;

void Do(int a, int b, int v){
	Mo[++Mc]=Move{a, b, v};
}

void Doo(int a, int r1, int r2, int v){
	Mo[++Mc]=Move{a, r1, v>>1};
	Mo[++Mc]=Move{r1, r2, -(v>>1)};
	Mo[++Mc]=Move{r2, a, v>>1};
}

void Deal(int l1, int l2, int r1, int r2, int v){
	Mo[++Mc]=Move{l1, r1, v>>1};
	Mo[++Mc]=Move{l2, r2, v>>1};
	Mo[++Mc]=Move{l1, l2, -(v>>1)};
	Mo[++Mc]=Move{r1, r2, -(v>>1)};
}

int main(){
	
	scanf("%d", &N);
	
	for(int i=1, a, b, c;i<N;++i){
		scanf("%d%d%d", &a, &b, &c);
		addE(a, b, c);addE(b, a, c);
		++V[a].Deg;++V[b].Deg;
	}
	
	for(int i=1;i<=N;++i){
		if(V[i].Deg==2){
			puts("NO");
			return 0;
		}
	}
	
	puts("YES");
	
	for(int i=1, a, b, l1, l2, r1, r2;i<=Ecnt;i+=2){
		a=E[i].y;b=E[i+1].y;
		if(V[a].Deg>V[b].Deg)	swap(a, b);
		if(V[a].Deg==1){
			if(V[b].Deg==1){
				Do(a, b, E[i].v);
			}
			else{
				Fetch_2(b, a, r1, r2);
				Doo(a, r1, r2, E[i].v);
			}
		}
		else{
			Fetch_2(a, b, l1, l2);
			Fetch_2(b, a, r1, r2);
			Deal(l1, l2, r1, r2, E[i].v);
		}
	}
	
	printf("%d\n", Mc);
	for(int i=1;i<=Mc;++i)	Mo[i].show();
	
	return 0;
}