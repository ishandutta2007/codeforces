#include <iostream>

using namespace std;

const int MAXN=200111;
const int MAXM=200111;
const int MAXQ=200111;
const int INF=1034567890;

int N, M, Qcnt;

struct To{
	int p, next;
} Too[MAXM<<1], Qoo[MAXQ];

int Toc, Qoc;

int Last[MAXQ];

struct Query{
	int a, b, c;
	int ans;
} Q[MAXQ];

struct Car{
	int a, b, c;
} C[MAXM];

struct Vert{
	int Son, Bro;
	int Dep;
	int Pre[19], Low[19];
	int Dps, Dpr;
	int Th, Qh;
} V[MAXN];

int Dfn[MAXN], DFN;

void DFS(int at){
	Dfn[++DFN]=at;
	V[at].Dps=DFN;
	for(int to=V[at].Son;to>0;to=V[to].Bro){
		V[to].Dep=V[at].Dep+1;
		DFS(to);
	}
	V[at].Dpr=DFN;
}

int LCA(int a, int b){
	if(V[a].Dep<V[b].Dep)	swap(a, b);
	for(int i=18;i>=0;--i)
		if(V[V[a].Pre[i]].Dep>=V[b].Dep)
			a=V[a].Pre[i];
	if(a!=b){
		for(int i=18;i>=0;--i){
			if(V[a].Pre[i]!=V[b].Pre[i]){
				a=V[a].Pre[i];
				b=V[b].Pre[i];
			}
		}
		a=V[a].Pre[0];
		b=V[b].Pre[0];
	}
	return (a+b)>>1;
}

void DFS_Low(int at){
	for(int to=V[at].Son;to>0;to=V[to].Bro){
		DFS_Low(to);
		if(V[V[to].Low[0]].Dep<V[V[at].Low[0]].Dep)
			V[at].Low[0]=V[to].Low[0];
	}
}

int Find(int a, int p, int &v){
	if(V[V[a].Low[17]].Dep>V[p].Dep){
		v-=INF;return -1;
	}
	if(a==p){
		v-=1;return 0;
	}
	for(int i=18;i>=0;--i)
		if(V[V[a].Low[i]].Dep>V[p].Dep){
			v+=(1<<i);
			a=V[a].Low[i];
		}
	return a;
}

int Coo[MAXN];

int lowbit(int a){
	return a&(-a);
}

void Add(int at, int d=1){
	for(int i=at;i<=N;i+=lowbit(i))
		Coo[i]+=d;
}

int Ask(int at){
	int ret=0;
	for(int i=at;i>0;i-=lowbit(i))
		ret+=Coo[i];
	return ret;
}

void Deal(int at){
	for(int k=V[at].Qh, to;k>0;k=Qoo[k].next){
		to=Qoo[k].p;
		Last[to]=Ask(V[Q[to].b].Dpr)-Ask(V[Q[to].b].Dps-1);
	}
	for(int k=V[at].Th, to;k>0;k=Too[k].next){
		to=Too[k].p;
		Add(V[to].Dps);
	}
	for(int to=V[at].Son;to>0;to=V[to].Bro){
		Deal(to);
	}
	for(int k=V[at].Qh, to;k>0;k=Qoo[k].next){
		to=Qoo[k].p;
		if(Ask(V[Q[to].b].Dpr)-Ask(V[Q[to].b].Dps-1)!=Last[to])	--Q[to].ans;
	}
}

int main(){
	
	cin >> N;
	for(int i=2, f;i<=N;++i){
		cin >> f;
		V[i].Bro=V[f].Son;V[f].Son=i;V[i].Pre[0]=f;
	}
	
	V[1].Dep=1;
	DFS(1);
	
	for(int j=1;j<19;++j)
		for(int i=1;i<=N;++i)
			V[i].Pre[j]=V[V[i].Pre[j-1]].Pre[j-1];
	
	for(int i=1;i<=N;++i)	V[i].Low[0]=i;
	
	cin >> M;
	
	for(int i=1, a, b, c;i<=M;++i){
		cin >> C[i].a >> C[i].b;
		C[i].c=LCA(C[i].a, C[i].b);
		a=C[i].a;b=C[i].b;c=C[i].c;
		if(V[c].Dep<V[V[a].Low[0]].Dep)
			V[a].Low[0]=c;
		if(V[c].Dep<V[V[b].Low[0]].Dep)
			V[b].Low[0]=c;
		++Toc;Too[Toc].p=b;Too[Toc].next=V[a].Th;V[a].Th=Toc;
		++Toc;Too[Toc].p=a;Too[Toc].next=V[b].Th;V[b].Th=Toc;
	}
	
	DFS_Low(1);
	
	for(int j=1;j<19;++j)
		for(int i=1;i<=N;++i)
			V[i].Low[j]=V[V[i].Low[j-1]].Low[j-1];
	
	cin >> Qcnt;
	
	for(int i=1, a, b;i<=Qcnt;++i){
		cin >> Q[i].a >> Q[i].b;
		Q[i].c=LCA(Q[i].a, Q[i].b);
		Q[i].ans=2;
		a=Find(Q[i].a, Q[i].c, Q[i].ans);
		b=Find(Q[i].b, Q[i].c, Q[i].ans);
		if(a>0 && b>0){
			Q[i].a=a;Q[i].b=b;
			++Qoc;Qoo[Qoc].p=i;Qoo[Qoc].next=V[a].Qh;V[a].Qh=Qoc;
		}
	}
	
	Deal(1);
	
	for(int i=1;i<=Qcnt;++i){
		if(Q[i].ans<=0)	puts("-1");
		else	printf("%d\n", Q[i].ans);
	}
	
	return 0;
}