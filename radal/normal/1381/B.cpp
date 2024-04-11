#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll unsigned long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const int N=4e3+30;
ll a[N],MAX[N],dp[N][N];
bool solver(ll sa,ll sb){
    ll n = sa+sb+1;
  //  debug(sa);debug(sb);debug(n);
    if (n == 1){
        return 1;
    }
    if (sa < sb) swap(sa,sb);
    if (sa < n-MAX[n-1]) return 0;
    if (sb < n-MAX[n-1]) return solver(sa-n+MAX[n-1],sb);
    if (solver(sa-n+MAX[n-1],sb)) return 1;
    else return solver(sb-n+MAX[n-1],sa);
}
int main(){
    int T;
    cin >> T;
    while (T--){       
        ll n;
        cin >> n;
        rep(i,1,2*n+1){
            cin >> a[i];
            MAX[i] = 0;
        }
        MAX[0] = 0;
        MAX[1] = 1;
        rep(i,2,2*n+1){
            if (a[i] > a[MAX[i-1]]){
                MAX[i] = i;
            }
            else{
                MAX[i] = MAX[i-1];
            }
        }
        dp[0][0] = 1;
        rep (i,1,n+1){
            if (i >= i+1-MAX[i]){
                dp[i][0] = 1;
                dp[0][i] = 1;
            }
        }
        rep (i,1,n+1){
            rep(j,1,n+1){
                if (max(i,j) < i+j+1 - MAX[i+j]){
                    dp[i][j] = 0;
                    continue;
                }
                if (min(i,j) < i+j+1-MAX[i+j]){
                   // debug(i);debug(j);
                    if (i > j){
                        dp[i][j] =  dp[MAX[i+j]-1-j][j];
                    }
                    else{
                        dp[i][j] = dp[i][MAX[i+j]-1-i];
                    }
                    continue;
                }
                dp[i][j] = (dp[i][MAX[i+j]-1-i] || dp[MAX[i+j]-1-j][j]);
            }
        }
    
        if (dp[n][n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}