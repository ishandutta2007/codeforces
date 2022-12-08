#include <iostream>
using namespace std;
const int MAXN=111111;
int N, M, Ecnt=0;
struct Node{
	int Dep, Size, FE, Pre[18];
} V[MAXN];
struct Edge{
	int x, y, next;
} E[MAXN<<1];
void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;
	E[Ecnt].y=b;
	E[Ecnt].next=V[a].FE;
	V[a].FE=Ecnt;
}
void DFS(int at){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Pre[0])	continue;
		V[to].Pre[0]=at;
		V[to].Dep=V[at].Dep+1;
		DFS(to);
		V[at].Size+=V[to].Size;
	}
}
int Jump(int at, int l){
	for(int i=17;i>=0;--i){
		if(l>=(1<<i)){
			l-=(1<<i);
			at=V[at].Pre[i];
		}
	}
	return at;
}
int LCA(int a, int b){
	if(V[a].Dep>V[b].Dep){
		for(int i=17;i>=0;--i){
			if(V[V[a].Pre[i]].Dep>=V[b].Dep)
				a=V[a].Pre[i];
		}
	}
	if(a!=b){
		for(int i=17;i>=0;--i){
			if(V[a].Pre[i]!=V[b].Pre[i]){
				a=V[a].Pre[i];
				b=V[b].Pre[i];
			}
		}
		a=V[a].Pre[0];
		b=V[b].Pre[0];
	}
	return a;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=1;i<=N;++i){
		V[i].Dep=0;
		V[i].Size=1;
		V[i].FE=-1;
		for(int j=0;j<18;++j)
			V[i].Pre[j]=0;
	}
	for(int i=1, a, b;i<N;++i){
		cin >> a >> b;
		addE(a, b);
		addE(b, a);
	}
	V[1].Pre[0]=1;
	V[1].Dep=1;
	DFS(1);
	for(int i=1;i<=17;++i){
		for(int j=1;j<=N;++j){
			V[j].Pre[i]=V[V[j].Pre[i-1]].Pre[i-1];
		}
	}
	cin >> M;
	for(int i=1, a, b, t, mid;i<=M;++i){
		cin >> a >> b;
		if(a==b){
			cout << N << endl;
			continue;
		}
		if(V[a].Dep<V[b].Dep){
			t=a;a=b;b=t;
		}
		if((V[a].Dep-V[b].Dep)%2==1){
			cout << "0" << endl;
			continue;
		}
		/*
		if(V[a].Dep==V[b].Dep){
			t=LCA(a, b);
			t=N-V[t].Size+1;
			cout << t << endl;
			continue;
		}
		t=LCA(a, b);
		t=(V[a].Dep+V[b].Dep)/2-V[t].Dep;
		t=V[Jump(a, t)].Size-V[Jump(a, t-1)].Size;
		cout << t << endl;
		*/
		t=LCA(a, b);
		if(V[a].Dep==V[b].Dep){
			t=(V[a].Dep+V[b].Dep)/2-V[t].Dep;
			a=Jump(a, t-1);
			b=Jump(b, t-1);
			t=N-V[a].Size-V[b].Size;
			cout << t << endl;
			continue;
		}
		t=(V[a].Dep+V[b].Dep)/2-V[t].Dep;
		t=V[Jump(a, t)].Size-V[Jump(a, t-1)].Size;
		cout << t << endl;
	}
	return 0;
}