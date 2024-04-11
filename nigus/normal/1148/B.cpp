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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 300001;

vl kind;
vl tim;
vl V;
vl ind;

vl B;

bool comp(ll i, ll j){
    if(tim[i] == tim[j]){
        return kind[i] < kind[j];
    }
    return tim[i] < tim[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    ll ta,tb;
    cin >> n >> m >> ta >> tb >> k;

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        kind.push_back(0);
        V.push_back(0);
        tim.push_back(a+ta);
        ind.push_back(sz(ind));
    }

    for(int c2 = 0; c2 < m; c2++){
        cin >> a;
        kind.push_back(1);
        V.push_back(a+tb);
        tim.push_back(a);
        ind.push_back(sz(ind));
        B.push_back(a+tb);
    }

    sort(all(B));
    sort(all(ind), comp);

    ll seen[2] = {0};
    ll ans = -1;

    for(int c1 = sz(ind)-1; c1 >= 0; c1--){
        a = ind[c1];
        if(kind[a] == 0){
            ll lft = n-seen[0]-1;
            if(lft <= k){
                ll bnext = m-seen[1] + k-lft;
                if(bnext >= m){
                    ans = big*big;
                }
                else{
                    ans = max(ans, B[bnext]);
                }
              //  cerr << tim[a] << " " << seen[1] << " gfd\n";
            }
        }
        seen[kind[a]]++;
    }
    if(n <= k || m <= k)ans = -1;
    if(ans == big*big)ans = -1;
    cout << ans << "\n";

    return 0;
}