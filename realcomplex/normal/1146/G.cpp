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

const int N = 52;
int dp[N][N][N];
int lose[N];

int main(){
    fastIO;
    int n, h, m;
    cin >> n >> h >> m;
    int l[m], r[m], x[m], c[m];
    for(int i = 0 ; i < m ; i ++ ){
        cin >> l[i] >> r[i] >> x[i] >> c[i];
    }
    int L, R;
    for(int len = 1; len <= 50 ; len ++ ){
        for(int i = 1; i <= n - len + 1; i ++ ){
            L = i;
            R = i + len - 1;
            for(int mid = L ; mid <= R ; mid ++ ){
                for(int x = 0 ;x <= h ; x ++ )
                    lose[x] = 0;
                for(int j = 0; j < m ; j ++ ){
                    if(l[j] <= mid && r[j] >= mid && l[j] >= L && r[j] <= R){
                        lose[x[j] + 1] += c[j];
                    }
                }
                for(int x = 1; x <= h ;x ++ )
                    lose[x] += lose[x - 1];
                for(int x = 0 ; x <= h ; x ++ ){
                    dp[L][R][x] = max(dp[L][R][x], dp[L][mid - 1][x] + dp[mid + 1][R][x] + x * x - lose[x]);
                }
            }
            for(int x = 1; x <= h ; x ++ ){
                dp[L][R][x] = max(dp[L][R][x], dp[L][R][x - 1]);
            }
        }
    }
    cout << dp[1][n][h] << "\n";
    return 0;
}