#include <iostream>
using namespace std;
const int MAXN=5111;
const long long INF=4567891012345678910LL;
int N, Ecnt;
long long ANS=INF, Now;
struct Node{
	int FE;
	long long Half, Way, Size, Val;
} V[MAXN];
struct Edge{
	int x, y, next;
	long long l;
} E[MAXN<<1];
void addE(int x, int y, long long l){
	++Ecnt;
	E[Ecnt].x=x;
	E[Ecnt].y=y;
	E[Ecnt].l=l;
	E[Ecnt].next=V[x].FE;
	V[x].FE=Ecnt;
}
void init(){
	for(int i=1;i<=N;++i){
		V[i].Size=1LL;
		V[i].Half=0LL;
		V[i].Way=0LL;
		V[i].Val=INF;
	}
}
void DFS1(int at, int f){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		DFS1(to, at);
		V[at].Size+=V[to].Size;
		V[at].Half+=V[to].Half+V[to].Size*E[k].l;
	}
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		V[at].Way+=V[to].Way;
		V[at].Way+=(V[to].Half+V[to].Size*E[k].l)*(V[at].Size-V[to].Size);
	}
}
int NN;
void DFS2(int at, int f){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		V[to].Val=V[at].Val+NN*E[k].l-2LL*V[to].Size*E[k].l;
		DFS2(to, at);
	}
}
long long DFS3(int at, int f){
	long long ret=V[at].Val;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		ret=min(ret, DFS3(to, at));
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	int a, b;
	long long c;
	Ecnt=0;
	for(int i=1;i<=N;++i){
		V[i].FE=-1;
		V[i].Size=1LL;
		V[i].Half=0LL;
		V[i].Way=0LL;
		V[i].Val=INF;
	}
	for(int i=1;i<N;++i){
		cin >> a >> b >> c;
		addE(a, b, c);
		addE(b, a, c);
	}
	long long lv, rv;
	for(int i=1;i<=Ecnt;i+=2){
		a=E[i].x;b=E[i].y;c=E[i].l;
		init();
		//cout << a << " " << b << endl;
		DFS1(a, b);
		V[a].Val=V[a].Half;
		NN=V[a].Size;
		DFS2(a, b);
		lv=DFS3(a, b);
		DFS1(b, a);
		V[b].Val=V[b].Half;
		NN=V[b].Size;
		DFS2(b, a);
		rv=DFS3(b, a);
		Now=lv*V[b].Size+rv*V[a].Size+c*V[a].Size*V[b].Size;
		Now+=(V[a].Way+V[b].Way);
		//cout << Now << endl;
		ANS=min(ANS, Now);
	}
	cout << ANS << endl;
	return 0;
}