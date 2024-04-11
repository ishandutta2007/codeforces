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

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 100004;

bool mark[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vi A;
        string s1;
        string s2;
        rep(c1,0,n){
            mark[c1] = 0;
        }

        cin >> s1 >> s2;
        rep(c1,0,n){
            if(s1[c1] != s2[c1]){
                A.push_back(2);
            }
            else{
                if(s1[c1] == '0'){
                    A.push_back(1);
                }
                else{
                    A.push_back(0);
                }
            }
        }

        ll ans = 0;
        rep(c1,0,n){
            if(A[c1] == 2){
                ans += 2;
            }
            else{

                if(A[c1] == 0){
                    if(c1 > 0 && A[c1-1] == 1 && mark[c1-1] == 0){
                        ans += 1;
                    }
                    else{
                        if(c1 < n-1 && A[c1+1] == 1){
                            mark[c1+1] = 1;
                            ans += 2;
                        }

                    }
                }
                if(A[c1] == 1){
                    if(!mark[c1]){
                        ans++;
                    }
                }

            }
        }
        cout << ans << "\n";

    }

    return 0;
}