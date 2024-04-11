#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e3+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
bool dp[N][N][2];
int n,a[N];
int main(){
    ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,0,n) cin >> a[i];
    rep(i,1,n){
        if (gcd(a[i],a[i-1]) > 1){
            dp[i][i][0] = 1;
            dp[i-1][i-1][1] = 1;
        }
    }
    repr(i,n-2,1){
        rep(j,i+1,n-1){
            rep(k,i,j+1){
                if (i == k){
                    if (dp[i+1][j][0] && gcd(a[k],a[i-1]) > 1){
                        dp[i][j][0] = 1;
                        break;
                    }
                    continue;
                }
                if (j == k){
                    if (dp[i][j-1][1] && gcd(a[k],a[i-1]) > 1){
                        dp[i][j][0] = 1;
                        break;
                    }
                    continue;
                }
                if (dp[i][k-1][1] && dp[k+1][j][0] && gcd(a[k],a[i-1]) > 1){
                    dp[i][j][0] = 1;
                    break;
                }
            }
            rep(k,i,j+1){
                if (i == k){
                    if (dp[i+1][j][0] && gcd(a[k],a[j+1]) > 1){
                        dp[i][j][1] = 1;
                        break;
                    }
                    continue;
                }
                if (j == k){
                    if (dp[i][j-1][1] && gcd(a[k],a[j+1]) > 1){
                        dp[i][j][1] = 1;
                        break;
                    }
                    continue;
                }
                if (dp[i][k-1][1] && dp[k+1][j][0] && gcd(a[k],a[j+1]) > 1){
                    dp[i][j][1] = 1;
                    break;
                }
            }
        }
    }
    rep(i,1,n-1){
        rep(j,0,i+1){
            if (!j){
                dp[0][i][1] = (dp[1][i][0] && gcd(a[0],a[i+1]) > 1);
                continue;
            }
            if (j == i){
                dp[0][i][1] |= (dp[0][i-1][1] && gcd(a[i+1],a[i]) > 1);
                continue;
            }
            dp[0][i][1] |= (dp[0][j-1][1] && dp[j+1][i][0] && gcd(a[n-1],a[j]) > 1);
        }
    }
    repr(i,n-2,1){
        rep(j,i,n){
            if (j == n-1){
                dp[i][n-1][0] |= (dp[i][n-2][1] && gcd(a[i-1],a[n-1]) > 1);
                continue;
            }
            if (j == i){
                dp[i][n-1][0] |= (dp[i+1][n-1][0] && gcd(a[i-1],a[i]) > 1);
                continue;
            }
            dp[i][n-1][0] |= (dp[i][j-1][1] && dp[j+1][n-1][0] && gcd(a[i-1],a[j]) > 1);
        }
    }
    rep(i,1,n-1){
        if (dp[0][i-1][1] && dp[i+1][n-1][0]){
            cout << "YES" << endl;
            return 0;
        }
    }
    if (dp[1][n-1][0] || dp[0][n-2][1]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}