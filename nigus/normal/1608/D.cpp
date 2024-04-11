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

const int MAXN = 200007;

ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i, j/2);
    if(j%2 == 0)return (h*h)%mod;
    return (((h*h)%mod)*i)%mod;
}

ll bin(ll i, ll j){
    if(i < 0 || j < 0 || i < j)return 0;
    ll a = (FAC[i] * INV[j])%mod;
    return (a * INV[i-j])%mod;
}

int pars(char ch){
    if(ch == '?')return 0;
    if(ch == 'W')return 1;
    if(ch == 'B')return 2;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    ll t = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        INV[c1] = upp(t, mod-2);
        t *= ll(c1+1);
        t %= mod;
    }

    cin >> n;
    ll F[3][3] = {0};
    int B = n;
    int W = n;
    rep(c1,0,n){
        string s;
        cin >> s;
        F[pars(s[0])][pars(s[1])]++;
    }
    rep(c1,0,3){
        rep(c2,0,3){
            B -= F[c1][c2] * (int(c1 == 2) + int(c2 == 2));
            W -= F[c1][c2] * (int(c1 == 1) + int(c2 == 1));
        }
    }
    if(B < 0 || W < 0){
        cout << "0\n";
        return 0;
    }

    ll base = bin(B+W, B);

    ll away = 0;
    if(F[1][1] > 0 || F[2][2] > 0){
        away = 0;
    }
    else{
        away = upp(2, F[0][0]);

        if(F[1][2] + F[1][0] + F[0][2] == 0){
            away += mod-1;
        }
        if(F[2][1] + F[2][0] + F[0][1] == 0){
            away += mod-1;
        }
    }

    away %= mod;

    cout << (base+mod-away)%mod << "\n";

    return 0;
}