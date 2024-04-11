#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const ll inf=1ll<<60;
// head
const double eps=1e-12;
const int N=2e5+5; 
const int mod=1e9+7;

ll powmod(ll x,ll k) {
	ll res=1;
	for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod;
	return res;
}

vector<ll> fac,inv;
void __init__(int n) {
	fac.resize(n); inv.resize(n);
	fac[0]=inv[0]=1;
	rep(i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	rep(i,1,n) inv[i]=(ll)powmod(fac[i],mod-2);
}
ll comb(int n,int m) {
	if (n<m) return 0;
	return fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n,k;
    ll ans=0;

    cin>>n>>k;

    if (k>n) k=n;

    __init__(n+1);

   	rep(i,0,k+1) {
   		ans=(ans+comb(n,i))%mod;
   	}

   	cout << ans << endl;

	return 0;
}