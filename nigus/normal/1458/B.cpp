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

const int MAXN = 300001;

int DP[101][20001] = {0};

vi A,B;

int D1[101][20001] = {0};
int D2[101][20001] = {0};

void dp2(){
    rep(c1,0,n+1){
        rep(c2,0,20001){
            D1[c1][c2] = -123456;
        }
    }
    D1[0][0] = 0;

    rep(i,0,n){
        rep(lft,0,n+1){
            rep(cap,0,20001){
                int temp = D1[lft][cap] + B[i]/2;
                if(cap >= A[i] && lft > 0){
                    int temp2 = D1[lft-1][cap-A[i]] + B[i];
                    temp = max(temp, temp2);
                }

                D2[lft][cap] = temp;
            }
        }
        rep(lft,0,n+1){
            rep(cap,0,20001){
                D1[lft][cap] = D2[lft][cap];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    rep(c1,0,n){
        cin >> a >> b;
        A.push_back(2*a);
        B.push_back(2*b);
    }

    dp2();

    rep(c1,1,n+1){
        int x = 0;
        rep(c2,0,20001){
            int tmp = min(c2,D1[c1][c2]);
            x = max(x, tmp);
        }
        cout << setprecision(18) << x/2.0 << " ";
    }cout << "\n";

    return 0;
}