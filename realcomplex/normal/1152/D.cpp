#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const ll MOD = (ll)1e9 + 7;

const int N = 2005;
ll dp[N][N];

void add(ll &a, ll b){
    a = (a + b) % MOD;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    n*=2;
    dp[0][0] = 1;
    ll res = 0;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j <= i; j ++ ){
            if(j > 0){
                add(dp[i][j], dp[i-1][j-1]);
            }
            add(dp[i][j], dp[i-1][j+1]);
        }
    }
    int rem;
    for(int i = 1; i <= n ; i += 2){
        for(int j = 0 ; j <= i ; j ++ ){
            rem = n - i;
            if(j <= rem){
                add(res,dp[i][j]);
            }
        }
    }
    cout << res;
    return 0;
}