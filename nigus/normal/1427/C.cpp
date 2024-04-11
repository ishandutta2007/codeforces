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

const int MAXN = 100101;

int DP[MAXN] = {0};
int MA[MAXN] = {0};

vi X,Y,TT;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> k >> n;

    X.push_back(1);
    Y.push_back(1);
    TT.push_back(0);

    rep(c1,0,n){
        cin >> a >> b >> c;
        X.push_back(b);
        Y.push_back(c);
        TT.push_back(a);
    }

    ll lim = 2*k+1;

    for(int c1 = n; c1 >= 0; c1--){
        ll L = min(n+1, c1+lim);
        DP[c1] = 1;
        rep(c2,c1+1,L){
            ll d = abs(X[c2]-X[c1]) + abs(Y[c2]-Y[c1]);
            if(d <= TT[c2] - TT[c1])DP[c1] = max(DP[c1], 1 + DP[c2]);
        }
        if(L <= n)DP[c1] = max(DP[c1], 1 + MA[L]);
        //cerr << DP[c1] << "  dsa\n";
        MA[c1] = max(DP[c1], MA[c1+1]);
    }

    cout << DP[0]-1 << "\n";

    return 0;
}