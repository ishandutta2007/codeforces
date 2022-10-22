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

ll P[MAXN] = {0};
ll PI[MAXN] = {0};

vector<pll> ANS;

void mov(ll i, ll j){
    if(i == j)return;
    if(abs(i-j)*2 < n){
        cerr << "ERROR\n";
    }
    ANS.push_back({i,j});
    ll t = P[i];
    P[i] = P[j];
    P[j] = t;
    PI[P[i]] = i;
    PI[P[j]] = j;
    return;
}

vl PP;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;

    for(int c1 = 0; c1 < n; c1++){
        PP.push_back(c1);
    }

    for(int c4 = 0; c4 < 1; c4++){
            ANS.clear();
    random_shuffle(all(PP));

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;

        a--;

       //a = PP[c1];

        P[c1] = a;
        PI[a] = c1;
    }

    for(int c1 = 0; c1 < n/2; c1++){
        ll x = n/2-c1-1;
        ll y = n/2+c1;

        if(x == 0){
            if(PI[x] == x)continue;
            mov(x,y);
            continue;
        }
    /*
        if(PI[x] >= n/2 && PI[y] < n/2){
            mov(PI[x], 0);
            mov(PI[y], n-1);
            mov(0, n-1);
            mov(n-1,x);
            mov(0,y);
        }
*/
        if(PI[x] == x && PI[y] == y)continue;

        if(PI[x] >= n/2){
            mov(0, PI[x]);
        }
        mov(PI[x], n-1);
        mov(n-1, x);

        if(PI[y] < n/2){
            mov(n-1, PI[y]);
        }
        mov(PI[y], 0);
        mov(0, y);

    }
    bool fail = 0;
    cout << sz(ANS) << "\n";
    for(int c1 = 0; c1 < sz(ANS); c1++){
        cout << ANS[c1].first+1 << " " << ANS[c1].second+1 << "\n";
        //if(abs(ANS[c1].first - ANS[c1].second) * 2 < n){fail = 1; cerr << "^ THIS ONE\n";}
    }


    for(int c1 = 0; c1 < n; c1++){
        //cerr << P[c1] << " ";
        if(P[c1] != c1){
            fail = 1;
        }
    }

    if(fail)break;

    }
    return 0;
}