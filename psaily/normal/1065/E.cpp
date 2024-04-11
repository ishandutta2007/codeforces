#include <bits/stdc++.h>
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
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;

const int N=2e5+5;
const int mod=998244353;

ll powmod(ll x,ll k){ll res=1;for(;k;k>>=1,x=x*x%mod)if(k&1)res=res*x%mod;return res;}

int n,m,A;
int a[N];


int main() {
	cin>>n>>m>>A;
	ll inv2=powmod(2,mod-2);
	rep(i,1,m+1) scanf("%d",&a[i]);
	ll ans=1;
	rep(i,1,m+1) {
		int len=a[i]-a[i-1];
		ll k=powmod(A,len);
		
		ans=ans*(k*(k-1)%mod*inv2%mod+k)%mod;
	}
	ans=ans*powmod(A,n-a[m]*2)%mod;
	printf("%lld\n",ans);
	return 0;	
}