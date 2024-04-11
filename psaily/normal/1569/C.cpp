#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int mod=998244353;
const int N=2e5+5;

int n,m,T;
int a[N];
ll fac[N],inv[N];

ll powmod(ll x,ll k) {
	ll res=1;
	for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod;
	return res;
}
void init() {
	fac[0]=inv[0]=1;
	rep(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mod;
	rep(i,1,N-1) inv[i]=powmod(fac[i],mod-2);
}
ll comb(int n,int m) {
	if (n<m) return 0;
	return fac[n]*inv[n-m]%mod*inv[m]%mod;	
}

int main() {
	init();
	scanf("%d",&T);
	while (T--) {	
		scanf("%d",&n);
		rep(i,1,n+1) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		
		if (a[n]==a[n-1]) printf("%lld\n",fac[n]);
		else if (a[n]>=a[n-1]+2) puts("0");
		else {
			int cnt=0;
			rep(i,1,n+1) if (a[i]==a[n-1]) cnt++;
			ll res=0;
			
			rep(i,cnt+1,n+1) {
				res=(res+comb(i-1,cnt)*fac[cnt]%mod*fac[n-1-cnt]%mod)%mod;
			}
			ll a=fac[n]-res;
			printf("%lld\n",(a%mod+mod)%mod);
		}	
	}
	
	
	return 0;
}