#include <iostream>
using namespace std;
const int MAXN=233333;
const long long INF=1034567890LL;
int N;
struct Node{
	int FE;
	long long Val;
	long long Dist[19];
	int Pre[19], Cnt, Ans;
} V[MAXN];
struct Edge{
	int x, y, next;
	long long l;
} E[MAXN<<1];
int Ecnt=0, prep;
long long length;
void addE(int a, int b, long long c){
	++Ecnt;
	E[Ecnt].x=a;
	E[Ecnt].y=b;
	E[Ecnt].next=V[a].FE;
	E[Ecnt].l=c;
	V[a].FE=Ecnt;
}
void DFS(int at){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Pre[0])	continue;
		V[to].Pre[0]=at;
		V[to].Dist[0]=E[k].l;
		DFS(to);
	}
}
int Jump(int at, int l){
	for(int i=18;i>=0;--i){
		if(l>=V[at].Dist[i]){
			l-=V[at].Dist[i];
			at=V[at].Pre[i];
		}
	}
	return at;
}
void getAns(int at){
	V[at].Ans=V[at].Cnt;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Pre[0])	continue;
		getAns(to);
		V[at].Ans+=V[to].Ans;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=1;i<=N;++i){
		cin >> V[i].Val;
		V[i].FE=-1;
		V[i].Cnt=0;
		V[i].Ans=0;
	}
	for(int i=2;i<=N;++i){
		cin >> prep >> length;
		addE(i, prep, length);
		addE(prep, i, length);
	}
	V[1].Pre[0]=1;
	V[1].Dist[0]=INF;
	DFS(1);
	for(int i=1;i<=18;++i){
		for(int j=1;j<=N;++j){
			V[j].Pre[i]=V[V[j].Pre[i-1]].Pre[i-1];
			V[j].Dist[i]=V[j].Dist[i-1]+V[V[j].Pre[i-1]].Dist[i-1];
		}
	}
	for(int i=1, j;i<=N;++i){
		j=Jump(i, V[i].Val);
		if(j!=1){
			--V[V[j].Pre[0]].Cnt;
			//cout << "--" << V[j].Pre[0] << endl;
		}	
		if(i!=1){
			++V[V[i].Pre[0]].Cnt;
			//cout << "++" << V[i].Pre[0] << endl;
		}
	}
	getAns(1);
	for(int i=1;i<=N;++i){
		cout << V[i].Ans << " ";
	}
	cout << endl;
	return 0;
}