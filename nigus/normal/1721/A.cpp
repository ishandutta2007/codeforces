#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef gp_hash_table<int,int> umap;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
 
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
ll n,m,k,q,T;
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
 
const ll MAXN = 300001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;
 
    cin >> T;
    rep(c4,0,T){
        int F[26] = {0};
        b = 0;
        rep(c1,0,2){
            string s;
            cin >> s;
            rep(c2,0,2){
                a = s[c2]-'a';
                if(F[a] == 0)b++;
                F[a]++;
            }
        }
        cout << b-1 << "\n";
    }
 
    return 0;
}