#include <iostream>
using namespace std;
const int MAXN=111111;
const int INF=1034567890;
int N, M, Q, Ecnt=0;
struct Node{
	int FE, People[19][11], Pre[19], Dep;
} V[MAXN];
struct Edge{
	int x, y, next;
} E[MAXN<<1];
int min(int a, int b){
	return (a<b)?a:b;
}
void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;
	E[Ecnt].y=b;
	E[Ecnt].next=V[a].FE;
	V[a].FE=Ecnt;
}
void DFS(int at, int d){
	V[at].Dep=d;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Pre[0])	continue;
		V[to].Pre[0]=at;
		DFS(to, d+1);
	}
}
void Merge(int C[], int A[], int B[]){
	int ret[11];
	for(int i=1;i<=10;++i)	ret[i]=INF;
	ret[0]=0;
	ret[0]=min(A[0]+B[0], 10);
	for(int i=1, j=1, k=1;i<=ret[0];++i){
		if(j>A[0] || A[j]>B[k])
			ret[i]=B[k++];
		else
			ret[i]=A[j++];
	}
	for(int i=0;i<=ret[0];++i)
		C[i]=ret[i];
}
void show(int Num[]){
	for(int i=0;i<=Num[0];++i)
		cout << Num[i] << " ";
	cout << endl;
}
void getANS(int a, int b, int k){
	int ANS[11];
	for(int i=1;i<=10;++i)	ANS[i]=INF;
	ANS[0]=0;
	if(V[a].Dep>V[b].Dep){
		for(int i=18;i>=0;--i){
			if(V[V[a].Pre[i]].Dep>=V[b].Dep){
				Merge(ANS, ANS, V[a].People[i]);
				a=V[a].Pre[i];
			}
		}
	}
	else if(V[a].Dep<V[b].Dep){
		for(int i=18;i>=0;--i){
			if(V[V[b].Pre[i]].Dep>=V[a].Dep){
				Merge(ANS, ANS, V[b].People[i]);
				b=V[b].Pre[i];
			}
		}
	}
	if(a!=b){
		for(int i=18;i>=0;--i){
			if(V[a].Pre[i]!=V[b].Pre[i]){
				Merge(ANS, ANS, V[a].People[i]);
				Merge(ANS, ANS, V[b].People[i]);
				a=V[a].Pre[i];
				b=V[b].Pre[i];
			}
		}
		Merge(ANS, ANS, V[a].People[0]);
		Merge(ANS, ANS, V[b].People[0]);
		a=V[a].Pre[0];
		b=V[b].Pre[0];
	}
	Merge(ANS, ANS, V[a].People[0]);
	ANS[0]=min(k, ANS[0]);
	show(ANS);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> Q;
	for(int i=0;i<=N;++i){
		V[i].FE=-1;
		for(int j=0;j<=18;++j){
			for(int k=1;k<=10;++k)
				V[i].People[j][k]=INF;
			V[i].People[j][0]=0;
			V[i].Pre[j]=0;
		}
		V[i].Dep=0;
	}
	for(int i=1, a, b;i<N;++i){
		cin >> a >> b;
		addE(a, b);
		addE(b, a);
	}
	for(int i=1, c;i<=M;++i){
		cin >> c;
		if(V[c].People[0][0]<10)	V[c].People[0][++V[c].People[0][0]]=i;
	}
	DFS(1, 1);
	for(int i=1;i<=18;++i){
		for(int j=1;j<=N;++j){
			V[j].Pre[i]=V[V[j].Pre[i-1]].Pre[i-1];
			Merge(V[j].People[i], V[j].People[i-1], V[V[j].Pre[i-1]].People[i-1]);
		}
	}
	/*
	for(int i=1;i<=N;++i){
		for(int j=0;j<=1;++j){
			cout << i << " " << j << ": ";
			show(V[i].People[j]);
		}
	}
	*/
	for(int i=1, a, b, c;i<=Q;++i){
		cin >> a >> b >> c;
		getANS(a, b, c);
	}
	return 0;
}