#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e6+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
ll a[N];
int cnt[N],cnt2[N];
int n;
bool f[N];
int binary(vector<ll> ve,ll val){
    int l = 0, r = ve.size(), m;
    while (r-l > 1){
        m = (l+r)/2;
        if (ve[m] <= val) l = m;
        else r = m;
    }
    return l;
}
int main(){
    ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,0,n) cin >> a[i];
   // random_shuffle(a,a+n);
    int u = min(11,n);
    ll ans = 1;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    rep(i,0,u){
        int x = (rng()%n);
        while (f[x] == 1) x = (rng()%n);
        f[x] = 1;

        int s = sqrt(a[x]),sz = 0;
        vector<ll> ve;
        rep(j,1,s+1){
            if (a[x]%j == 0){
                ve.pb(j);
                cnt[sz] = 0;
                cnt2[sz] = 0;
                sz++;
                if (a[x]/j != j){
                    ve.pb(a[x]/j);
                    cnt[sz] = 0;
                    cnt2[sz] = 0;
                    sz++;
                }
            }
        }
        sort(ve.begin(),ve.end());
        rep(j,0,n){
            ll g = gcd(a[x],a[j]);
            cnt[lower_bound(ve.begin(),ve.end(),g)-ve.begin()]++;
        }
        repr(j,sz-1,0){
            rep(k,0,sz){
                if (ve[k]%ve[j] == 0) cnt2[j] += cnt[k];
                if (cnt2[j] >= (n+1)/2) break;
            }
            if (cnt2[j] >= (n+1)/2) break;
        }
        repr(j,sz-1,0){
            if (cnt2[j] >= (n+1)/2){
                ans = max(ans,ve[j]);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}