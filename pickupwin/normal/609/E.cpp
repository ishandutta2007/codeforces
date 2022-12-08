#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=200111;
const int MAXM=200111;

int N, M;
int F[MAXN];
long long Sum;

int Find(int a){
	if(F[F[a]]!=F[a])	F[a]=Find(F[a]);
	return F[a];
}

struct Data{
	int x, y, l;
	int id;
} D[MAXM];

bool cmpl(Data A, Data B){
	return A.l<B.l;
}

bool cmpid(Data A, Data B){
	return A.id<B.id;
}

struct Vert{
	int FE;
	int Dep;
	int Pre[19], Dis[19];
} V[MAXN];

struct Edge{
	int x, y, l, next;
} E[MAXN<<1];

int Ecnt;

void addE(int a, int b, int c){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].l=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

void DFS(int at, int f=0){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		V[to].Pre[0]=at;
		V[to].Dep=V[at].Dep+1;
		V[to].Dis[0]=E[k].l;
		DFS(to, at);
	}
}

int Ask(int a, int b){
	if(V[a].Dep<V[b].Dep)	swap(a, b);
	int ret=0;
	for(int i=18;i>=0;--i)
		if(V[V[a].Pre[i]].Dep>=V[b].Dep){
			ret=max(ret, V[a].Dis[i]);
			a=V[a].Pre[i];
		}
	if(a!=b){
		for(int i=18;i>=0;--i){
			if(V[a].Pre[i]!=V[b].Pre[i]){
				ret=max(ret, V[a].Dis[i]);
				a=V[a].Pre[i];
				ret=max(ret, V[b].Dis[i]);
				b=V[b].Pre[i];
			}
		}
		ret=max(ret, V[a].Dis[0]);
		a=V[a].Pre[0];
		ret=max(ret, V[b].Dis[0]);
		b=V[b].Pre[0];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=1;i<=M;++i){
		cin >> D[i].x >> D[i].y >> D[i].l;
		D[i].id=i;
	}
	
	for(int i=1;i<=N;++i)	F[i]=i;
	
	sort(D+1, D+M+1, cmpl);
	
	for(int i=1, a, b;i<=M;++i){
		a=D[i].x;b=D[i].y;
		a=Find(a);b=Find(b);
		if(a!=b){
			addE(D[i].x, D[i].y, D[i].l);
			addE(D[i].y, D[i].x, D[i].l);
			F[a]=b;
			Sum+=D[i].l;
		}
	}
	
	//cout << "!!!" << Sum << endl;
	
	V[1].Dep=1;
	DFS(1);
	
	for(int j=1;j<19;++j){
		for(int i=1;i<=N;++i){
			V[i].Pre[j]=V[V[i].Pre[j-1]].Pre[j-1];
			V[i].Dis[j]=max(V[i].Dis[j-1], V[V[i].Pre[j-1]].Dis[j-1]);
		}
	}
	
	sort(D+1, D+M+1, cmpid);
	
	for(int i=1, d;i<=M;++i){
		d=D[i].l-Ask(D[i].x, D[i].y);
		cout << Sum+d << endl;
	}
	
	return 0;
}