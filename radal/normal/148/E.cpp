#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 1e2+30,inf = 1e10,mod=1e9+7,M=1e5+30;
vector <int> a[N];
ll dp[N][M],pre[N][N],suf[N][N],Dp[N][M];
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        int s;
        cin >> s;
        a[i].resize(s);
        rep(j,0,s){
        //    debug(i);debug(j);
            cin >> a[i][j];
        }
       // cout << i;
    }
    rep(i,0,n){
        int s=a[i].size();
        repr(j,s-1,0){
            suf[i][j] = a[i][j]+suf[i][j+1];
        }
        rep(j,0,N){
            if(j >= s){
                pre[i][j] = pre[i][j-1];
                continue;
            }
            if (!j) pre[i][j] = a[i][j];
            else pre[i][j] = pre[i][j-1] + a[i][j];
        }
        dp[i][0] = 0;
    }
    rep(i,0,n){
        int s=a[i].size();
        rep(j,0,s+1){
            rep(k,0,j+1){
                if (k)Dp[i][j] = max(Dp[i][j],pre[i][k-1]+suf[i][s-j+k]);
                else Dp[i][j] = suf[i][s-j];
            }
        }
    }

    rep (i,0,n){
        rep(j,1,m+1){
            int s=a[i].size();
            if (j <= s){
                rep (k,0,j) {
                    if (i) dp[i][j] = max(Dp[i][k]+dp[i-1][j-k],dp[i][j]);
                    else dp[i][j] = max(dp[i][j],dp[i][k]);
                    if (i ==n-3 && j == m){
                      //  debug(k);
                    //    debug(dp[i][j]);
                    }
                }
                dp[i][j] = max(dp[i][j],Dp[i][j]);
            }
            else{
                rep(k,0,s+1){
                    if (i) {
                        dp[i][j] = max(dp[i][j],dp[i-1][j-k]+Dp[i][k]);
                //        if (i == n-2) debug(dp[i][j]); 
                    }
                    else dp[i][j] = max(dp[i][j],dp[i][j-1]);
                }
            }
            if (j <= 6){
                //    debug(i); debug(j); debug(dp[i][j]);
            }   
        }
     //   debug(dp[0][10]);
    }
    debug(dp[n-3][3]);
    debug(dp[n-3][m]);

    cout << dp[n-1][m]<<endl;

}