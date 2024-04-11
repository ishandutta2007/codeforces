#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 100000;

vl ind;
ll A,B;

ll bs1(ll i){
    ll l = 0;
    ll r = k;
    if(i <= ind[0])return 0;
    while(l < r-1){
        ll mid = (l+r)/2;
        if(ind[mid] >= i){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r;
}

ll bs2(ll i){
    ll l = 0;
    ll r = k-1;
    if(i >= ind[k-1])return k-1;
    if(i < ind[0])return -1;

    while(l < r-1){
        ll mid = (l+r)/2;
        if(ind[mid] <= i){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}

unordered_map<ll,ll> M;


ll dp(ll i, ll j){
    ll l = bs1(i);
    ll r = bs2(j);

    if(l > r)return A;
    ll h = i*big+j;
    if(M.find(h) != M.end())return M[h];
    ll ans = big*big;
    ans = min(ans, (r-l+1)*(j-i+1)*B);
    if(i != j){
        ll mid = (i+j)/2;
        ans = min(ans, dp(i,mid) + dp(mid+1,j));
    }
    M[h] = ans;
   // cerr << i << " ij  " << j << "  --  " << l << "  lr  " << r << "  --  " << ans << "\n";
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k >> A >> B;
    for(int c1 = 0; c1 < k; c1++){
        cin >> a;
        a--;
        ind.push_back(a);
    }
    sort(all(ind));
    ll ans = dp(0,(1<<n)-1);
    cout << ans << "\n";

    return 0;
}