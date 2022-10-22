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
 
const ll MAXN = 2000006;

vector<vi> C(MAXN, vi());
vl L, R;

int ans = 0;

ll dfs(int i){
    ll res = 0;
    ll stuff = 0;
    trav(y, C[i]){
        stuff += dfs(y);
    }
    if(stuff < L[i]){
        ans++;
        stuff = R[i];
    }
    stuff = min(stuff, R[i]);
    return stuff;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d,e;
    
    cin >> T;
    rep(c4,0,T){
        L.clear();
        R.clear();
        cin >> n;
        rep(c1,0,n){
            C[c1].clear();
        }
        rep(c1,1,n){
            cin >> a;
            a--;
            C[a].push_back(c1);
        }
        rep(c1,0,n){
            cin >> a >> b;
            L.push_back(a);
            R.push_back(b);
        }
        ans = 0;
        dfs(0);
        cout << ans << "\n";
    }
 
    return 0;
}