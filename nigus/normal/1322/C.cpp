#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1000001;

ll gcd(ll i, ll j){
    if(i == 0)return j;
    if(j == 0)return i;
    return gcd(j,i%j);
}

vl A;
vector<pll> B;

ll base = 0;

ll P[MAXN] = {0};
ll Q[MAXN] = {0};

unordered_map<ll,ll> M;
vl SUM;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;

    base = random2()%big + 1234567;

    a = 1;
    b = 1;
    rep(c1,0,MAXN){
        P[c1] = a;
        Q[c1] = b;
        a *= base;
        b *= base;
        a %= big;
        b %= big2;
    }

    rep(c4,0,T){
        cin >> n >> m;
        A.clear();
        B.clear();
        M.clear();
        SUM.clear();
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            B.push_back({0,0});
        }
        rep(c1,0,m){
            cin >> a >> b;
            a--;
            b--;
            B[b].first += P[a];
            B[b].first %= big;
            B[b].second += Q[a];
            B[b].second %= big2;
        }
        ll ans = 0;
        rep(c1,0,n){
            ll h = B[c1].first * big2 + B[c1].second;
            if(h == 0)A[c1] = 0;
            if(M.find(h) == M.end()){
                M[h] = sz(SUM);
                SUM.push_back(0);
            }
            SUM[M[h]] += A[c1];
        }
        trav(x, SUM){
            ans = gcd(ans, x);
        }

        cout << ans << "\n";



    }

    return 0;
}