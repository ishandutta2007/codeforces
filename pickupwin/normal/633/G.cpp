#include <iostream>
#include <bitset>
#include <cassert>

using namespace std;

const int MAXN=100111;
const int MAXM=1011;

int N, MOD, M;
int Pcnt;
int P[MAXM];
bool isP[MAXM];

struct Vert{
	int FE;
	int Dps, Dpr;
	int Num;
} V[MAXN];

struct Edge{
	int x, y, next;
} E[MAXN<<1];

int Ecnt=0;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

int DFN=0, Dfn[MAXN];

void DFS(int at, int f=0){
	++DFN;Dfn[DFN]=at;V[at].Dps=DFN;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		DFS(to, at);
	}
	V[at].Dpr=DFN;
}

struct Node{
	int l, r;
	bitset<MAXM> data;
	int opt;
} T[MAXN<<2];

int L, R, op;
bitset<MAXM> ANS;

void pup(int at){
	T[at].data=T[at<<1].data|T[(at<<1)|1].data;
}

void BuildTree(int l, int r, int at){
	T[at].l=l;T[at].r=r;T[at].opt=0;
	int m=(l+r)>>1;
	if(l==r){
		T[at].data[V[Dfn[m]].Num]=1;
		return;
	}
	BuildTree(l, m, at<<1);
	BuildTree(m+1, r, (at<<1)|1);
	pup(at);
}

void opr(int at){
	T[at].data=(T[at].data<<op)|(T[at].data>>(MOD-op));
}

void cop(int at){
	T[at].opt+=op;
	if(T[at].opt>=MOD)	T[at].opt-=MOD;
}

void pdw(int at){
	if(T[at].opt==0)	return;
	int top=op;op=T[at].opt;
	opr(at<<1);cop(at<<1);
	opr((at<<1)|1);cop((at<<1)|1);
	op=top;T[at].opt=0;
}

void Update(int at){
	if(T[at].l>=L && T[at].r<=R){
		opr(at);cop(at);
		return;
	}
	pdw(at);
	int m=(T[at].l+T[at].r)>>1;
	if(L<=m)	Update(at<<1);
	if(R>m)	Update((at<<1)|1);
	pup(at);
}

bitset<MAXM> Ask(int at){
	if(T[at].l>=L && T[at].r<=R){
		return T[at].data;
	}
	pdw(at);
	int m=(T[at].l+T[at].r)>>1;
	bitset<MAXM> ret;
	if(L<=m)	ret=ret|Ask(at<<1);
	if(R>m)	ret=ret|Ask((at<<1)|1);
	return ret;
}

int Calc(){
	int ret=0;
	for(int i=1;i<=Pcnt;++i){
		if(ANS[P[i]]==1)	++ret;
	}
	return ret;
}

void show(int at=1){
	string str=T[at].data.to_string();
	cout << T[at].l << " " << T[at].r << ": ";
	cout << str << endl;
	if(T[at].l!=T[at].r){
		pdw(at);
		show(at<<1);show((at<<1)|1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> MOD;
	for(int i=1;i<=N;++i)	cin >> V[i].Num;
	for(int i=1;i<=N;++i)	V[i].Num%=MOD;
	
	for(int i=2;i<MOD;++i)	isP[i]=true;
	for(int i=2;i<MOD;++i){
		if(isP[i])	P[++Pcnt]=i;
		for(int j=1;j<=Pcnt && P[j]*i<MOD;++j){
			isP[i*P[j]]=false;
			if(i%P[j]==0)	break;
		}
	}
	
	//for(int i=1;i<=Pcnt;++i)	cout << P[i] << " ";
	//cout << endl;
	
	for(int i=1, a, b;i<N;++i){
		cin >> a >> b;
		addE(a, b);addE(b, a);
	}
	
	DFS(1);
	assert(DFN==N);
	
	BuildTree(1, N, 1);
	
	cin >> M;
	for(int t, v;M--;){
		cin >> t >> v;
		L=V[v].Dps;R=V[v].Dpr;
		//cout << "AT " << L << " " << R << endl;
		if(t==1){
			cin >> op;
			op%=MOD;
			Update(1);
		}
		else{
			ANS=Ask(1);
			cout << Calc() << endl;
		}
		//show();
	}
	
	return 0;
}