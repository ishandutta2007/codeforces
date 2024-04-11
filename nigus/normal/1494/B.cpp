#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(i = a; i < (b); ++i)
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

string s,t;

int fram[MAXN] = {0};
int bak[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    int c4;
    rep(c4,0,T){
        cin >> n >> a >> b >> c >> d;
        int A[4] = {0};
        string ans = "NO";
        rep(A[0],0,2){
            rep(A[1],0,2){
                rep(A[2],0,2){
                    rep(A[3],0,2){
                        ll a2 = a - A[0] - A[3];
                        ll b2 = b - A[1] - A[0];
                        ll c2 = c - A[2] - A[1];
                        ll d2 = d - A[3] - A[2];
                        if(a2 >= 0 && b2 >= 0 && c2 >= 0 && d2 >= 0){
                            if(a2 < n-1 && b2 < n-1 && c2 < n-1 && d2 < n-1){
                                ans = "YES";
                            }
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}