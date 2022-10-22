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

const int MAXN = 5001;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vi A(n);
        rep(c1,0,n){
            cin >> A[c1];
        }
        vi ans = {1};
        rep(c1,1,n){
            rep(c2,0,sz(ans)){
                cout << ans[c2];
                if(c2 < sz(ans)-1)cout << ".";
            }cout << "\n";
            if(A[c1] == ans.back() + 1){
                ans[sz(ans)-1] = A[c1];
            }
            else{
                if(A[c1] == 1){
                    ans.push_back(1);
                }
                else{
                    while(A[c1] != ans.back() + 1){
                        ans.pop_back();
                    }
                    ans[sz(ans) - 1]++;
                }
            }
        }

        rep(c2,0,sz(ans)){
                cout << ans[c2];
                if(c2 < sz(ans)-1)cout << ".";
            }cout << "\n";
    }

    return 0;
}