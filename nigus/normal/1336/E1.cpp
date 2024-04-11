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

const int MAXN = 200001;
const int MAXM = 53;

vector<bitset<MAXN> > VB;
vector<bitset<MAXM> > HL;

vl A;

vi zeros;

void gauss(){
    bool pivot[MAXM] = {0};

    rep(col,0,n){
        int row = -1;
        rep(c1,0,m){
            if(VB[c1][col] == 1 && !pivot[c1]){
                row = c1;
                break;
            }
        }
        if(row != -1){
            pivot[row] = 1;
            rep(r,0,m){
                if(r != row && VB[r][col] == 1){
                    VB[r] ^= VB[row];
                    HL[r] ^= HL[row];
                }
            }
        }

    }

    rep(c1,0,m){
        if(VB[c1].count() == 0)zeros.push_back(c1);
    }
}

ll fri = 0;

unordered_map<ll,ll> M;

ll ANS[MAXM] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m;

    rep(c1,0,m){
        bitset<MAXN> temp;
        bitset<MAXM> temp2;
        temp2[c1] = 1;
        VB.push_back(temp);
        HL.push_back(temp2);
    }

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        rep(c2,0,m){
            VB[c2][c1] = a%2;
            a /= 2;
        }
    }

    if(m == 0){
        ll ans = 1;
        rep(c1,0,n){
            ans *= 2;
            ans %= mod;
        }
        cout << ans << "\n";
        return 0;
    }

    gauss();
    fri = n - m + sz(zeros);
   // cerr << fri << "\n";

    ll tf = 1;
    rep(c1,0,fri){
        tf *= 2;
        tf %= mod;
    }



    /*
    rep(c1,0,m){
        rep(c2,0,m){
            cerr << HL[c1][c2];
        }cerr << "\n";
    }
    */

    ll one = m/2;
    ll rest = m-one;

    rep(mask, 0, (1 << one)){
        bitset<MAXM> B;
        int m2 = mask;
        rep(c1,0,m){
            B[c1] = m2%2;
            m2 /= 2;
        }

        ll pp = B.count();

        ll m3 = 0;
        trav(z,zeros){
            m3 *= 2;
            m3 += ((B&HL[z]).count())%2;
        }
        ll h = m3 * MAXM + pp;
        if(M.find(h) == M.end()){
            M[h] = 0;
        }
        M[h]++;
    }

    rep(mask, 0, (1 << rest)){
        bitset<MAXM> B;
        int m2 = mask;
        rep(c1,0,m){
            B[c1+one] = m2%2;
            m2 /= 2;
        }

        ll pp = B.count();

        ll m3 = 0;
        trav(z,zeros){
            m3 *= 2;
            m3 += ((B&HL[z]).count())%2;
        }

        rep(p1,0,one+1){
            ll h = m3 * MAXM + p1;
            if(M.find(h) != M.end()){
                ANS[pp + p1] += M[h];
                ANS[pp + p1] %= mod;
            }
        }
    }

    rep(c1,0,m+1){
        cout << (tf*ANS[c1])%mod << " ";
    }cout << "\n";

    return 0;
}