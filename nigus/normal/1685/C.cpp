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
 
const int MAXN = 300006;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c,d,e;
    
    cin >> T;
    rep(c4,0,T){
        int prev = -1;
        cin >> n;
        vi sum;
        sum.push_back(0);
        string s;
        cin >> s;
        rep(c1,0,2*n){
            int diff = 1;
            if(s[c1] == ')')diff = -1;
            sum.push_back(sum.back()+diff);
        }
        
        int mi = 2*n+1;
        int mi_i = -1;
        int ma = -2*n-1;
        int ma_i = -1;

        rep(c1,0,2*n+1){
            if(sum[c1] > ma){
                ma = sum[c1];
                ma_i = c1;
            }
            if(sum[c1] < mi){
                mi = sum[c1];
                mi_i = c1;
            }
        }

        if(mi == 0){
            cout << "0\n";
            continue;
        }

        int lm = 0;
        int li = 0;
        rep(c1,0,2*n+1){
            if(sum[c1] < 0)break;
            if(sum[c1] > lm){
                lm = sum[c1];
                li = c1;
            }
        }
        int ri = 2*n;
        int rm = 0;
        for(int c1 = 2*n; c1 >= 0; c1--){
            if(sum[c1] < 0)break;
            if(sum[c1] > rm){
                rm = sum[c1];
                ri = c1;
            }
        }

        if(rm+lm-ma >= 0){
            cout << "1\n";
            cout << li+1 << " " << ri << "\n";
            continue;
        }

        cout << "2\n";

        if(ma+mi >= 0){
            cout << 1 << " " << ma_i << "\n";
            cout << ma_i+1 << " " << 2*n << "\n"; 
        }
        else{
            int j = mi_i;
            while(sum[j] < 0){
                 j++;
            }

            cout << 1 << " " << j << "\n";
            cout << j-mi_i+1 << " " << 2*n << "\n";

        }

    }
    

    return 0;
}