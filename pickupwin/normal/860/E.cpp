#include <cstdio>
#include <algorithm>

using std::max;

const int MAXN=500111;

int N;

struct Data{
	int Cnt, Id;
	long long Val;
	int next;
	Data(){}
	Data(int _c, int _i, long long _v){Cnt=_c;Id=_i;Val=_v;}
} T[MAXN<<2];

int Tcnt;

namespace Map{
	
	struct Vert{
		int FE;
		long long Val;
	} V[MAXN];
	
	struct Edge{
		int x, y;
		long long l;
		int next;
	} E[MAXN];
	
	int Ecnt;
	
	void addE(int a, int b, long long c){
		++Ecnt;
		E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].l=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
	}
	
	void DFS(int at){
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			V[to].Val=V[at].Val+E[k].l;
			DFS(to);
		}
	}
	
}

namespace Tree{
	
	struct Vert{
		int FE;
		int Fa, Son;
		int Dep, Len;
		int Head;
		long long Ans;
	} V[MAXN];
	
	struct Edge{
		int x, y, next;
	} E[MAXN<<1];
	
	int Ecnt;
	
	void addE(int a, int b){
		++Ecnt;
		E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
	}
	
	void DFS1(int at){
		//printf("DFS1 %d\n", at);
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			if(to==V[at].Fa)	continue;
			V[to].Dep=V[at].Dep+1;
			V[to].Fa=at;
			DFS1(to);
			V[at].Len=max(V[at].Len, V[to].Len+1);
			if(V[at].Son<=0 || V[V[at].Son].Len<V[to].Len)	V[at].Son=to;
		}
	}
	
	void Merge(int p, Data &A, Data &d){
		d.Val+=1LL*V[p].Dep*A.Cnt;
		A.Val+=1LL*V[p].Dep*d.Cnt;
		Map::addE(A.Id, d.Id, d.Val-A.Val);
		A.Cnt+=d.Cnt;
	}
	
	void DFS2(int at){
		//printf("DFS2 %d\n", at);
		if(V[at].Son)	DFS2(V[at].Son);
		T[++Tcnt]=Data(1, at, 0);
		V[at].Head=Tcnt;T[Tcnt].next=V[V[at].Son].Head;
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			if(to==V[at].Fa || to==V[at].Son)	continue;
			DFS2(to);
			for(int a=T[V[at].Head].next, p=V[to].Head;p>0;a=T[a].next, p=T[p].next){
				Merge(at, T[a], T[p]);
			}
		}
		/*
		printf("DFS2 %d\n", at);
		for(int p=V[at].Head;p>0;p=T[p].next){
			printf("%d %d %I64d\n", T[p].Cnt, T[p].Id, T[p].Val);
		}
		*/
	}
	
	void DFS3(int at){
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			if(to==V[at].Fa)	continue;
			V[to].Ans=V[at].Ans+Map::V[to].Val+V[at].Dep;
			DFS3(to);
		}
	}
	
}

int main(){
	
	scanf("%d", &N);
	
	int Root;
	
	for(int i=1, f;i<=N;++i){
		scanf("%d", &f);
		if(f==0)	Root=i;
		else	{Tree::addE(i, f);Tree::addE(f, i);}
	}
	
	Tree::V[Root].Dep=1;
	Tree::DFS1(Root);
	Tree::DFS2(Root);
	
	for(int p=Tree::V[Root].Head;p>0;p=T[p].next){
		Map::V[T[p].Id].Val=T[p].Val;
		Map::DFS(T[p].Id);
	}
	
	//for(int i=1;i<=N;++i)	printf("%I64d\n", Map::V[i].Val);
	
	Tree::DFS3(Root);
	
	for(int i=1;i<=N;++i)	printf("%I64d ", Tree::V[i].Ans);
	puts("");
	
	return 0;
}

/*
4
0 1 2 1

0 2 4 2

*/