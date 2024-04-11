#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=5e3+30,mod = 1e9+7,inf=1e9;
string a[N],b[N];
int dp[N][30][30];
pair<int,int> par[N][30][30];
int main(){
    int n,m,ans=inf,I,J;
    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i];
        rep(j,0,30) rep(k,0,30) dp[i][j][k] = 5e5;
    }
    char c,d;
    rep(i,0,26){
        rep(j,0,26){
            if (i == j) continue;
            c = char(int('a')+i);
            d = char(int('a')+j);
            int cnt=0;
            rep(k,0,m){
                if ((k%2 && a[0][k] != d) || (k%2 == 0 && a[0][k] != c)){
                    cnt++;
                }
            }
            dp[0][i][j] = cnt;
            if (n == 1){
                if (dp[0][i][j] < ans){
                    ans = dp[0][i][j];
                    I = i;
                    J = j;
                }
            }
        }
    }
    if (n == 1){
        cout << ans << endl;
        char c = char(int('a')+I);
        char d = char(int('a')+J);
        rep(i,0,m){
            if (i%2) cout << d;
            else cout << c;
        }
        return 0;
    }
    rep(i,1,n){
        rep(j,0,26){
            rep(k,0,26){
                if (j == k) continue;
                rep(x,0,26){
                    if (x == j) continue;
                    rep(y,0,26){
                        if (y == k) continue;
                        if (dp[i][j][k] > dp[i-1][x][y]){
                            dp[i][j][k] = dp[i-1][x][y];
                            par[i][j][k] = {x,y};
                        }
                    }
                }
                char c = char(int('a')+j), d = char(int('a')+k);
                rep(x,0,m){
                    if ((x%2 && a[i][x] != d) || (x%2 == 0 && a[i][x] != c)){

                        dp[i][j][k]++;
                    }
                }
                if (i == n-1){
                    if (ans > dp[i][j][k]){
                        ans = min(ans,dp[i][j][k]);
                        I = j;
                        J = k;
                    }
                }
            }
        }
    }
    cout << ans<<endl;
    repr(i,n-1,0){
        char c = char(int('a')+I);
        char d = char(int('a')+J) ;
        rep(j,0,m){
            if (j%2) b[i] += d;
            else b[i] += c;
        }
        int p = I;
        I = par[i][p][J].X;
        J = par[i][p][J].Y;
    }
    rep(i,0,n) cout << b[i] << endl;
}