#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=500111, MAXM=500111;
const int MOD=1000000007;

int sr;
int sum(int a, int b){
	sr=a+b;
	if(sr>=MOD)	sr-=MOD;
	return sr;
}

int mul(int a, int b){
	return (int)((1LL*a*b)%(1LL*MOD));
}

int N, M, K;
long long Num[MAXN];
int Pow[MAXN];

int Cnt;
int F[MAXN], Size[MAXN];

int Find(int a){
	return (a==F[a])?a:Find(F[a]);
}

struct Modi{
	int *p, o;
	Modi(){}
	Modi(int* _p, int _o){p=_p;o=_o;}
	void ud(){
		(*p)=o;
	}
} Mo[MAXM<<1];

int Mc;

void Modify(int &p, int v){
	Mo[++Mc]=Modi(&p, p);
	p=v;
}

struct Edge{
	int x, y;
	long long v;
} E[MAXM];

bool cmpv(Edge A, Edge B){
	return A.v<B.v;
}

void Link(int a, int b){
	a=Find(a);b=Find(b);
	if(a==b)	return;
	--Cnt;
	if(Size[a]>Size[b])	swap(a, b);
	Modify(F[a], b);
	Modify(Size[b], Size[a]+Size[b]);
}

void Clear(){
	Cnt=N;
	for(int i=Mc;i>=1;--i)	Mo[i].ud();
	Mc=0;
}

int Ans=0;

void Calc(long long t){
	//cout << Cnt << " " << t << endl;
	Ans=sum(Ans, Pow[Cnt]);
	--t;
	Ans=sum(Ans, mul(Pow[N], (int)(t%(long long)(MOD))));
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	for(int i=1;i<=M;++i){
		cin >> E[i].x >> E[i].y;
		E[i].v=Num[E[i].x]^Num[E[i].y];
	}
	
	Pow[0]=1;
	for(int i=1;i<=N;++i)	Pow[i]=sum(Pow[i-1], Pow[i-1]);
	
	sort(E+1, E+M+1, cmpv);
	
	for(int i=1;i<=N;++i){
		F[i]=i;
		Size[i]=1;
	}
	Cnt=N;
	
	long long pv=0LL;
	for(int i=1;i<=M;++i){
		if(E[i].v!=pv){
			Calc(E[i].v-pv);
			Clear();
		}
		pv=E[i].v;
		Link(E[i].x, E[i].y);
	}
	Calc((1LL<<K)-pv);
	
	cout << Ans << endl;
	
	return 0;
}