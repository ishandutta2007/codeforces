#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
ll dp[3][N];
int a[N];
int b[N];

void upd(ll &a, ll b){
    a = max(a, b);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n;  i ++ )
        cin >> a[i];
    for(int i = 1; i <= n; i ++ )
        cin >> b[i];
    for(int i = 1; i <= n ; i ++ ){
        upd(dp[0][i], max({dp[0][i-1], dp[1][i-1], dp[2][i-1]}));
        upd(dp[1][i], max(dp[0][i-1], dp[2][i-1]) + a[i]);
        upd(dp[2][i], max(dp[0][i-1], dp[1][i-1]) + b[i]);
    }
    ll res = max({dp[0][n], dp[1][n], dp[2][n]});
    cout << res;
    return 0;
}