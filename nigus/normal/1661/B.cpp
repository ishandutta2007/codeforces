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

const int MAXN = 200101;

ll ANS1[MAXN] = {0};
ll ANS2[MAXN] = {0};

const ll MOD = 32768;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    for(int c1 = 0; c1 < MOD; c1++){
        int t = 0;
        int cc = c1;
        while(cc != 0){
            cc *= 2;
            cc %= MOD;
            t++;
        }
        ANS1[c1] = t;
    }

    for(int c1 = MOD-1; c1 >= 1; c1--){
        ANS2[c1] = min(1+ANS2[(c1+1)%MOD], ANS1[c1]);
    }

    rep(c4,0,T){
        cin >> n;
        cout << ANS2[n] << "\n";
    }

    return 0;
}