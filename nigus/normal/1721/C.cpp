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
        cin >> n;
        vl A;
        vl B;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        rep(c1,0,n){
            cin >> a;
            B.push_back(a);
        }
        vi MI;
        int lo = 0;
        rep(c1,0,n){
            while(lo <= c1 && B[lo] < A[c1]){
                lo++;
            }
            MI.push_back(B[lo]-A[c1]);
        }
        
        int last_bad = n;
        vi MA;
        
        for(int c1 = n-1; c1 >= 0; c1--){
            MA.push_back(B[last_bad-1]-A[c1]);
            if(c1 > 0){
                if(B[c1-1] < A[c1])last_bad = c1;
            }
        }
        reverse(all(MA));
        
        rep(c1,0,n){
            cout << MI[c1] << " ";
        }cout << "\n";
        rep(c1,0,n){
            cout << MA[c1] << " ";
        }
        
        cout << "\n";
    }
 
    return 0;
}