//#pragma GCC optimize("O3")   //
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

const int big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 4000004;

int diff[MAXN] = {0};

int mo(int x){
    if(x < 0)return x + m;
    if(x >= m)return x - m;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> n >> m;

    ll sum = 0;
   // diff[1] = 1;

    rep(c1,1,n+1){
        diff[c1] += diff[c1-1];
        diff[c1] = mo(diff[c1]);
        ll dp = mo(sum + diff[c1]);
        if(c1 == 1)dp = 1;
        if(c1 == n){
            cout << dp << "\n";
            break;
        }
        for(int c2 = 2*c1; c2 < MAXN; c2 += c1){
            diff[c2] = mo(diff[c2] + dp);
            if(c2 + c2/c1 < MAXN)diff[c2 + c2/c1] = mo(diff[c2 + c2/c1] - dp);
        }
        sum = mo(sum + dp);
       // cerr << c1 << ": " << dp << "\n";
    }



    return 0;
}