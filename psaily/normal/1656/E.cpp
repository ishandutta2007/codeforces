#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;

template<class T> void rd(T &x) {
	static int c,f;x=f=0;
	while(c=getchar(),c<48) if(c=='-') f=1;
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);if(f) x=-x;
}
template<class T> void pt(T x) {
	if(x<0) putchar('-'),x=-x;
	else if(!x) putchar('0');
	static int Stk[30],tp=0;
	for(; x; x/=10) Stk[tp++]=x%10;
	while(tp) putchar(Stk[--tp]^48);
}
template<class T> void ptk(const T &x) {
	pt(x);putchar(' ');
}
template<class T> void ptn(const T &x) {
	pt(x);putchar('\n');
}
template<class T> bool chkmi(T &x,const T &y) {
	return x>y?x=y,true:false;
}
template<class T> bool chkmx(T &x,const T &y) {
	return x<y?x=y,true:false;
}

const int N=2e5+50;
vector<int> E[N];
int deg[N],dep[N];
void dfs(int x,int fr) {
	dep[x]=dep[fr]+1;
	for(auto y: E[x]) if(y!=fr) dfs(y,x);
}
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) E[i].clear(),deg[i]=0;
	FOR(i,2,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
		++deg[x];
		++deg[y];
	}
	dfs(1,0);
	FOR(i,1,n) {
		int r=deg[i];
		if(dep[i]&1) ;
		else r=-r;
		printf("%d%c",r," \n"[i==n]);
	}
}
int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}