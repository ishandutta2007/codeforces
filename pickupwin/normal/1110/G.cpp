#include <cstdio>

const int MAXN=2000111;

int T;

char Co[MAXN];

int N;

struct Vert{
	int FE;
	int Deg;
} V[MAXN];

struct Edge{
	int y, next;
} E[MAXN<<1];

int Ecnt;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

bool Win;

bool Test(int at){
	int c=0;
	for(int k=V[at].FE, to;k;k=E[k].next){
		to=E[k].y;
		c+=V[to].Deg>1;
	}
	return c>1;
}

int Cnt3;

int main(){
	
	scanf("%d", &T);
	
	while(T--){
		
		scanf("%d", &N);
		
		for(int i=1, a, b;i<N;++i){
			scanf("%d%d", &a, &b);
			addE(a, b);addE(b, a);
			++V[a].Deg;++V[b].Deg;
		}
		
		scanf("%s", Co+1);
		
		for(int i=N;i>=1;--i){
			if(Co[i]=='W'){
				++N;
				addE(i, N);addE(N, i);
				++V[i].Deg;++V[N].Deg;
				++N;
				addE(N-1, N);addE(N, N-1);
				++V[N-1].Deg;++V[N].Deg;
				++N;
				addE(N-2, N);addE(N, N-2);
				++V[N-2].Deg;++V[N].Deg;
			}
		}
		
		Win=false;
		
		for(int i=1;i<=N;++i)	if(V[i].Deg>=4)	Win=true;
		
		for(int i=1;i<=N;++i)	if(V[i].Deg==3)	Win|=Test(i);
		
		if(!Win){
			
			Cnt3=0;
			for(int i=1;i<=N;++i)	Cnt3+=V[i].Deg==3;
			
			if((Cnt3>1) && (N&1))	Win=true;
			
		}
		
		puts(Win?"White":"Draw");
		
		for(int i=1;i<=N;++i){
			V[i].FE=0;
			V[i].Deg=0;
		}
		Ecnt=0;
		
		N=0;
		
	}
	
	return 0;
}