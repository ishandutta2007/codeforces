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

const ll MAXN = 100001;

ll B[100][100] = {0};
ll BT[100][100] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%big;
    return (((h*h)%big) * (i%big))%big;
}

void mul_with(vector<vl> &M1, vector<vl> &M2){
    ll N = sz(M1);
    rep(c1,0,N){
        rep(c2,0,N){
            B[c1][c2] = 0;
            BT[c1][c2] = M2[c2][c1];
        }
    }
    rep(c1,0,N){
        rep(c2,0,N){
            rep(c3,0,N){
                B[c1][c2] += (M1[c1][c3] * BT[c2][c3])%(big-1);
                B[c1][c2] %= big-1;
            }
        }
    }

    rep(c1,0,N){
        rep(c2,0,N){
            M1[c1][c2] = B[c1][c2];
        }
    }
}

vector<vl> M1;
vector<vl> R1;

vector<vl> M2;
vector<vl> R2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    M1.push_back({0,1,0});
    M1.push_back({0,0,1});
    M1.push_back({1,1,1});

    R1.push_back({1,0,0});
    R1.push_back({0,1,0});
    R1.push_back({0,0,1});

    M2.push_back({0,1,0,0,0});
    M2.push_back({0,0,1,0,0});
    M2.push_back({1,1,1,2,0});
    M2.push_back({0,0,0,1,1});
    M2.push_back({0,0,0,0,1});

    R2.push_back({1,0,0,0,0});
    R2.push_back({0,1,0,0,0});
    R2.push_back({0,0,1,0,0});
    R2.push_back({0,0,0,1,0});
    R2.push_back({0,0,0,0,1});

    ll f1,f2,f3;
    cin >> n >> f1 >> f2 >> f3 >> c;

    n -= 3;
    ll t = 0;

    for(ll c1 = 59; c1 >= 0; c1--){
        mul_with(R1, R1);
        mul_with(R2, R2);
        t *= 2;
        if(((1ll << ll(c1)) & n) != 0){
            mul_with(R1, M1);
            mul_with(R2, M2);
            t++;
        }
    }
    assert(t == n);
    //cerr << t << "\n";
    ll ff[3] = {f1,f2,f3};
    ll F[3] = {0};
    ll ans = 1;


    //rep(c1,0,5){rep(c2,0,5){cerr << R2[c1][c2] << " ";}cerr << "\n";}

    rep(c1,0,3){
        rep(c2,2,3){
            F[c1] += R1[c2][c1];
        }
        F[c1] %= big;
        ans *= upp(ff[c1], F[c1]);
        ans %= big;
    }

    ll fff[5] = {0, 0, 0, 1, 1};

    ll cf = (R2[2][3] + R2[2][4])%(big-1);
    //cerr << cf << "\n";
    c %= big;
    ans *= upp(c, cf);
    ans %= big;

    cout << ans << "\n";

    return 0;
}