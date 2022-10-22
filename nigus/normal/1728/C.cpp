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
 
const ll MAXN = 200001;

int root(int x){
    int t = 1;
    int hej = 0; 
    while(1){
        if(x < t){
            return hej;
        }
        t*=10;
        hej++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;
    
    cin >> T;

    rep(c4,0,T){
        cin >> n;

        vi A;
        vi B;
        
        priority_queue<int> pqa,pqb;

        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            pqa.push(a);
        }
        rep(c1,0,n){
            cin >> a;
            B.push_back(a);
            pqb.push(a);
        }
        int ans = 0;

        while(sz(pqa) > 0){
            a = pqa.top();
            pqa.pop();
            b = pqb.top();
            pqb.pop();
            if(a == b){
                continue;
            }
            else{
                if(a > b){
                    ans++;
                    pqa.push(root(a));
                    pqb.push(b);
                }
                else{
                    ans++;
                    pqb.push(root(b));
                    pqa.push(a);
                }
            }
        }

        cout << ans << "\n";



    }
    
    return 0;
}