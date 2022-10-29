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
typedef __int128 ll;
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
ll gcd(ll a,ll b) { return !b?a:gcd(b,a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b%mod; } 


int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin>>n;

    vector<ll> phi(n+1);
    iota(phi.begin(),phi.end(),0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            phi[j] -= phi[i];
        }
    }

    // rep(i,1,n+1) cout << phi[i] << endl;

    ll ans=0;
    //debug(ans);

    rep(g,1,n+1) {
    	for (int k=2;k*g<n;k++) {
    		int c=n-k*g;
    		ans=(ans+lcm(c,g)*phi[k]%mod)%mod;
    	}
    }

    ans=(ans%mod+mod)%mod;
    long long res=ans;

    cout << res << endl;


	return 0;
}