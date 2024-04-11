#include<bits/stdc++.h>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
const int mod=998244353;
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int val[2005][2005];
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	int mul=POW(m,n),inv=POW(m,mod-2);
	FOR(i,1,min(k,n)){
		mul=mul*(n-i+1)%mod;mul=mul*inv%mod;mul=mul*((m+1)/2)%mod;
		ans=(ans+val[k][i]*mul)%mod;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	val[0][0]=1;
	FOR(i,1,2000){
		FOR(j,1,i){
			val[i][j]=(val[i-1][j-1]+val[i-1][j]*j)%mod;
		}
	}
	while(T--)solve();
	RE 0;
}