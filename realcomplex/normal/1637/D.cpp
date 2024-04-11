#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
const int M = N * N;
int dp[N][M];
int A[N];
int B[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int res = 0;
        for(int i = 1; i <= n; i ++ ){
            cin >> A[i];
            res += A[i] * 1ll * A[i] * 1ll * (n - 1);
        }
        for(int i = 1; i <= n; i ++ ){
            cin >> B[i];
            res += B[i] * 1ll * B[i] * 1ll * (n - 1);
        }
        int total = 0;
        for(int j = 1; j < M ; j ++ ){
            dp[0][j] = (int)1e9;
        }
        int ax;
        int bx;
        for(int i = 1; i <= n; i ++ ){
            for(int p = 0 ; p < M; p ++ ){
                dp[i][p] = (int)1e9;
            }
            for(int p = 0 ; p < M ; p ++ ){
                if(dp[i-1][p] < (int)1e9){
                    dp[i][p + A[i]] = min(dp[i][p + A[i]], dp[i-1][p] + p * A[i] + (total - p) * B[i]);
                    dp[i][p + B[i]] = min(dp[i][p + B[i]], dp[i-1][p] + p * B[i] + (total - p) * A[i]);
                }
            }
            total += A[i];
            total += B[i];
        }
        int low = (int)1e9;
        for(int j = 0 ; j < M ; j ++ )
            low = min(low, dp[n][j]);
        cout << res + 2ll * low << "\n";
    }
    return 0;
}