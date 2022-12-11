#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
const ll inf = (ll)1e18;

ll dp[N];
ll A[N], B[N];

ll d;
ll f(int j){
    return dp[j]-B[j]-2ll*d*j;
}

int main(){
    fastIO;
    int n;
    ll r1, r2, r3;
    cin >> n >> r1 >> r2 >> r3 >> d;
    ll x;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        dp[i] = inf;
        A[i] = x * r1 + r3;
        B[i] = min(r1 * (x + 2), r1 + r2);
        B[i] = min(B[i], A[i]);
        B[i] += B[i - 1];
    }
    dp[0]=0;
    ll low = inf;
    for(int i = 1; i <= n; i ++ ){
        dp[i] = dp[i - 1] + A[i];
        if(i > 1){
            low = min(low, f(i - 2));
            dp[i] = min(dp[i],low + B[i] + d * 2ll * (i - 1));
        }
    }
    ll res = dp[n];
    for(int i = 1; i <= n - 1; i ++ ){
        res = min(res, dp[i-1] + A[n] + B[n - 1] - B[i - 1] + (n - i) * d);
        //res = min(res, dp[i-1] + B[n] - B[i - 1] + (n - i) * 1ll * d + 2ll * d);
    }
    cout << res + d * 1ll * (n - 1);
    return 0;
}