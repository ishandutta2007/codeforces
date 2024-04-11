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

const int MAXN = 200001;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    string s1,s2;
    cin >> s1 >> s2;
    n = sz(s1);
    m = sz(s2);
    int extra = 0;
    rep(c1,0,m-1){
        if(s2[c1] != s2[c1+1])extra++;
    }
    extra %= 2;
    int ans = 0;
    int parity = 0;
    rep(c1,0,m){
        parity += (s1[c1] != s2[c1]);
    }
    parity %= 2;
    ans += (parity^1);

    rep(c1,0,n-m){
        parity ^= (s1[c1] != s2[0]);
        parity ^= (s1[c1+m] != s2[m-1]);
        parity ^= extra;
        ans += (parity^1);
    }

    cout << ans << "\n";

    return 0;
}