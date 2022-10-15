
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define INF (1ll<<58)
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef std::pair<ll,ll> pll;
typedef std::string str;
//---------END-------//
const int M=998244353;
int MUL(int x,int y){
	return (long long)x*y%M;
}
typedef pair<int,int> p;
int f[1000010],n,m,a[1010][1010];
p g[1000010];
int r,c;
bool cmp(p x,p y){
	return a[x.first][x.second]<a[y.first][y.second];
}
int fp(int x,int y){
	int ret=1;
	for (; y; y>>=1,x=MUL(x,x)) if (y&1) ret=MUL(ret,x);
	return ret;
}
void U(int &x){
	x<0?x+=M:0;
}
int main(){
	int k=0;
	cin>>n>>m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j){
		    cin>>a[i][j];
			g[++k]=p(i,j);
		}
		cin>>r>>c;
	sort(g+1,g+k+1,cmp);
	int num=1,prec=0,prex=0,prey=0;
	for (int i=1; i<=k; ++i){
		while (cmp(g[num],g[i])){
			(prec+=(g[num].first*g[num].first)+(g[num].second*g[num].second))%=M;
			(prec+=f[num])%=M;
			(prex+=g[num].first)%=M;
			(prey+=g[num].second)%=M;
			++num;
		}
		int xx,yy;
		xx=g[i].first;
		yy=g[i].second;
		f[i]=prec;
		U(f[i]-=2ll*prex*xx%M);
		U(f[i]-=2ll*prey*yy%M);
		(f[i]+=(long long)(xx*xx+yy*yy)*(num-1)%M)%=M;
		f[i]=MUL(f[i],fp(num-1,M-2));
		if (g[i].first==r&&g[i].second==c){
			printf("%d\n",f[i]);
			break;
		}
	}
}