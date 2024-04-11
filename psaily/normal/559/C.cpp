#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef unsigned long long ull;
// head

const int N=2e5+5;
const int mod=1e9+7;
int h,w,n;
pii p[N];
ll inv[N],fac[N],dp[N];

ll powmod(ll x,ll k) {ll res=1;for(;k;k>>=1,x=x*x%mod)if(k&1)res=res*x%mod;return res;}
ll comb(int n,int m) {// n!/(n-m)!/(m!)
	return 1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int main() {
	scanf("%d%d%d",&h,&w,&n);
	fac[0]=inv[0]=1;
	rep(i,1,N) fac[i]=fac[i-1]*i%mod;
	rep(i,1,N) inv[i]=powmod(fac[i],mod-2);
	// printf("%lld\n",comb(5,1));
	rep(i,1,n+1) scanf("%d%d",&p[i].fi,&p[i].se);
	sort(p+1,p+1+n);
	ll ans=comb(h+w-2,w-1);
	debug(ans);
	rep(i,1,n+1) {
		dp[i]=comb(p[i].fi+p[i].se-2,p[i].fi-1);
		rep(j,1,i) if (p[j].fi<=p[i].fi&&p[j].se<=p[i].se) {
			int x=p[i].fi-p[j].fi,y=p[i].se-p[j].se;
			(dp[i]-=dp[j]*comb(x+y,y)%mod)%=mod;
		}
		// printf("dp[%d]=%lld\n",i,dp[i]);
	}
	rep(i,1,n+1) (ans-=dp[i]*comb(h+w-p[i].fi-p[i].se,h-p[i].fi)%mod)%=mod;
	if (ans<0) ans+=mod;
	printf("%lld\n",ans);
	return 0;	
}