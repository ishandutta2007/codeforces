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

set<ll> cubes;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    for(ll c1 = 1; c1 <= 40001; c1++){
        cubes.insert(c1*c1*c1);
    }

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        string ans = "NO";
        for(ll A = 1; A <= n; A++){
            ll BC = n - A*A*A;
            if(BC <= 0)break;
            if(cubes.find(BC) != cubes.end()){
                ans = "YES";
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}