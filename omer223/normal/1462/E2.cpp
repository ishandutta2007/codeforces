#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7, sz = 2e5+5;
ll f[sz],invf[sz];

ll modpow(ll a, ll b){
    if(!b)return 1;
    ll tmp = modpow(a,b>>1);
    tmp*=tmp;
    tmp%=mod;
    if(b&1){
        tmp*=a;
        tmp%=mod;
    }
    return tmp;
}

void prec() {
    f[0]=1;
    foru(i,1,sz)f[i]=(f[i-1]*i)%mod;
    invf[sz-1]=modpow(f[sz-1],mod-2);
    ford(i,sz-2,0)invf[i]=(invf[i+1]*(i+1))%mod;
}

inline ll choose(const ll& x, const ll& y) {
    if(x<y||x<0)return 0;
    return ((f[x]*invf[y])%mod *invf[x-y])%mod;
}

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n), rng(n,0);
    foru(i,0,n)cin>>a[i];
    if(m==1){
        cout<<n<<'\n';
        return;
    }
    sort(a.begin(),a.end());
    int l=0,r=0;
    ll tot =0;
    while(l<n){
        while(r<n&&a[r]-a[l]<=k)r++;
        rng[l++]=r;
    }
    foru(i,0,n){
        tot+=choose(rng[i]-i-1,m-1);
        tot%=mod;
    }
    cout<<tot<<'\n';

}

int main() {
    fast;
    prec();
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}