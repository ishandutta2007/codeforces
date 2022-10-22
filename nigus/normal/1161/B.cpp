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

vector<vi> C(100001, vi());

ll base = 1567452;

ll bp1[100001] = {0};
ll bp2[100001] = {0};

vl H1, H2;

ll eye = 0;

bool comp(ll i, ll j){
    return (i-eye+n)%n < (j-eye+n)%n;
}

ll has(ll i, ll mo){
    ll ans = 0;
    eye = i;
    sort(all(C[i]),comp);
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = (C[i][c1]-i+n)%n;
        ans *= base;
        ans += a;
        ans %= mo;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    base = random(10000000);

    cin >> n >> m;
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    ll t1 = 1;
    ll t2 = 1;
    for(int c1 = 0; c1 < n+1; c1++){
        bp1[c1] = t1;
        bp2[c1] = t2;
        t1 *= base;
        t2 *= base;
        t1 %= big;
        t2 %= big2;
    }

    for(int c1 = 0; c1 < n; c1++){
        H1.push_back(has(c1,big));
        H2.push_back(has(c1,big2));
       // cerr << H1[c1] << " ";
    }//cerr << "\n";

    t1 = 1;
    t2 = 1;
    ll h1 = 0;
    ll h2 = 0;
    for(int c1 = 0; c1 < n; c1++){
        h1 *= base;
        h2 *= base;
        h1 += H1[c1];
        h2 += H2[c1];
        h1 %= big;
        h2 %= big2;
    }

    ll h0 = h1*big2 + h2;

    for(int c1 = 1; c1 < n; c1++){
        h1 -= (bp1[n-1]*H1[c1-1])%big;
        h1 += 10*big;
        h1 %= big;
        h1 *= base;
        h1 += H1[c1-1];
        h1 %= big;

        h2 -= (bp2[n-1]*H2[c1-1])%big2;
        h2 += 10*big2;
        h2 %= big2;
        h2 *= base;
        h2 += H2[c1-1];
        h2 %= big2;

        if(h1*big2 + h2 == h0){
            cout << "Yes\n";
            return 0;
        }

    }
    cout << "No\n";

    return 0;
}