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

const int MAXN = 300001;

ll PATH[401][401] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> k;

    rep(c1,0,401){
        rep(c2,0,401){
            if(c1 == 0 && c2 == 1)PATH[c1][c2] = 1;
            if(c2 == 0)PATH[c1][c2] = 1;
        }
    }

    rep(i,1,k){
        for(ll r = 1; r < k+1; r++){
            rep(x,0,r+2){
                if(x < r)PATH[i][r] += (PATH[i-1][x] * PATH[i-1][r-1-x]);
                if(x < r+1)PATH[i][r] += (1 + 2*r) * ((PATH[i-1][x] * PATH[i-1][r-x])%big);
                PATH[i][r] += r*(r+1)*((PATH[i-1][x] * PATH[i-1][r-x+1])%big);
                PATH[i][r] %= big;
            }
        }
    }

    cout << PATH[k-1][1] << "\n";

    return 0;
}