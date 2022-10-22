#pragma GCC optimize("O3")
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
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 1000004;

ll rowpar[MAXN][2] = {0};
ll broken_rows = 0;
ll empty_rows = 0;
ll colpar[MAXN][2] = {0};
ll broken_cols = 0;
ll empty_cols = 0;
ll occupied = 0;


ll sumpar[2] = {0};

ll two[MAXN] = {0};

bool brokenr(ll i){
    return (rowpar[i][0] != 0 && rowpar[i][1] != 0);
}

bool brokenc(ll i){
    return (colpar[i][0] != 0 && colpar[i][1] != 0);
}

unordered_map<ll,ll> M;

ll geta(ll i, ll j){
    ll h = i*MAXN + j;
    if(M.find(h) == M.end())return -1;
    return M[h];
}

void seta(ll i, ll j, ll c){
    ll h = i*MAXN + j;
    M[h] = c;
}

ll cross(){
    return (sumpar[0] == 0) + (sumpar[1] == 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m >> k;

    ll t = 1;
    rep(c1,0,MAXN){
        two[c1] = t;
        t *= 2;
        t %= mod;
    }

    empty_cols = m;
    empty_rows = n;

    rep(c1,0,k){
        cin >> a >> b >> c;
        a--;
        b--;

        ll br1 = brokenr(a);
        ll bc1 = brokenc(b);
        ll er1 = (rowpar[a][0] == 0 && rowpar[a][1] == 0);
        ll ec1 = (colpar[b][0] == 0 && colpar[b][1] == 0);

        ll ab = geta(a, b);
        if(ab != -1){
            rowpar[a][(ab^(b%2))]--;
            colpar[b][(ab^(a%2))]--;
            sumpar[(a+b+ab)%2]--;

            occupied--;
        }

        seta(a, b, c);
        if(c != -1){
            rowpar[a][(c^(b%2))]++;
            colpar[b][(c^(a%2))]++;
            sumpar[(a+b+c)%2]++;
            occupied++;
        }

        ll br2 = brokenr(a);
        ll bc2 = brokenc(b);
        ll er2 = (rowpar[a][0] == 0 && rowpar[a][1] == 0);
        ll ec2 = (colpar[b][0] == 0 && colpar[b][1] == 0);

        broken_rows += br2-br1;
        broken_cols += bc2-bc1;
        empty_rows += er2-er1;
        empty_cols += ec2-ec1;

        ll ans = 0;

        if(broken_rows == 0){
            ans += two[empty_rows];
        }
        if(broken_cols == 0){
            ans += two[empty_cols];
        }
        ans %= mod;

        /*
        ll overlap = (broken_rows == 0 && broken_cols == 0);
        if(overlap > 0)overlap += (occupied == 0);
        */
        ll overlap = cross();

        ans -= overlap;
        ans += mod;
        ans %= mod;
        cout << ans << "\n";

      //  cerr << "broken_rows: " << broken_rows << "  ,  " << "broken_cols: " << broken_cols << "\n";

    }


    return 0;
}