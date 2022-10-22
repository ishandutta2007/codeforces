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

const ll MAXN = 1000004;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        string s;
        cin >> s;
        n = sz(s);
        ll ans = MAXN;

        int z = -1;
        for(int c1 = n-1; c1 >= 0; c1--){
            if(s[c1] == '0'){
                z = c1;
                break;
            }
        }
        if(z != -1){
            int w = -1;
            for(int c1 = z-1; c1 >= 0; c1--){
                if(s[c1] == '0' || s[c1] == '5'){
                    w = c1;
                    break;
                }
            }
            if(w != -1){
                ans = n - w - 2;
            }
        }

        z = -1;
        for(int c1 = n-1; c1 >= 0; c1--){
            if(s[c1] == '5'){
                z = c1;
                break;
            }
        }
        if(z != -1){
            int w = -1;
            for(int c1 = z-1; c1 >= 0; c1--){
                if(s[c1] == '2' || s[c1] == '7'){
                    w = c1;
                    break;
                }
            }
            if(w != -1){
                ans = min(ans,n - w - 2);
            }
        }

        if(ans == MAXN){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }

    }


    return 0;
}