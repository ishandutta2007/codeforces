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

const ll MAXN = 3004;

int DP[MAXN][MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        vector<vi> C(n, vi());
        vi A;
        int prev = -12;
        rep(c1,0,n){
            cin >> a;
            a--;
            if(a != prev){
                A.push_back(a);
                C[a].push_back(sz(A)-1);
            }
            prev = a;
        }

        n = sz(A);

        for(int L = 1; L <= n; L++){
            for(int i = 0; i < n-L+1; i++){

                int j = i+L-1;
                if(L == 1){
                    DP[i][j] = 0;
                }
                else{
                    DP[i][j] = 1 + DP[i+1][j];
                    DP[i][j] = min(DP[i][j], 1 + DP[i][j-1]);

                    if(A[i] == A[j]){
                        DP[i][j] = min(DP[i][j], 1 + DP[i+1][j-1]);
                    }

                    trav(ii, C[A[i]]){
                        if(ii > i && ii < j){
                            if(A[i] == A[j]){
                                DP[i][j] = min(DP[i][j], DP[i][ii] + DP[ii][j]);
                            }
                            DP[i][j] = min(DP[i][j], DP[i][ii] + DP[ii+1][j] + 1);
                        }
                    }

                    trav(jj, C[A[j]]){
                        if(jj > i && jj < j){
                            DP[i][j] = min(DP[i][j], DP[i][jj-1] + DP[jj][j] + 1);
                        }
                    }

                   // cerr << i+1 << " " << j+1 << "   -   " << DP[i][j] << "  sdf\n";

                }
            }
        }

        cout << DP[0][n-1] << "\n";

    }

    return 0;
}