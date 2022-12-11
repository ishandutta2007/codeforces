#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 765;
const ll inf = (ll)4e18;

ll dp[N][N];
ll f[N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    ll a[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
    }
    for(int i = 0 ; i < N; i ++ ){
        for(int j = 0 ; j < N ; j ++ ){
            dp[i][j] = -inf;
        }
    }
    dp[n][0] = 0;
    for(int i = n - 1; i >= 0 ; i -- ){
        for(int j = 0 ; j <= n; j ++ ){
            dp[i][j] = min(a[i]+dp[i + 1][j],a[i]);
            if(j>0){
                dp[i][j] = max(dp[i][j], dp[i+1][j-1]);
            }
        }
    }
    for(int j = 0 ; j <= n; j ++ )
        f[j] = dp[0][j];
    ll b;
    for(int i = 1; i <= m; i ++ ){
        cin >> b;
        for(int i = 0 ; i <= n; i ++ ){
            if(b + f[i] >= 0){
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}