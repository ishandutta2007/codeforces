#include <iostream>

using namespace std;

int a[200002], dp[200002], DP[200002], DP_max[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];

    int l = 1, r = n;
    while(l < r){
        int mid = (l + r + 1)/2;
        bool flag = false;
        for(int i=1;i<=n;i++){
            if(a[i] >= mid) dp[i] = dp[i-1] + 1;
            else dp[i] = dp[i-1];
            DP[i] = i - 2 * dp[i];
            DP_max[i] = max(DP_max[i-1], DP[i]);
        }

        for(int i=k;i<=n;i++){
            if(DP[i] < DP_max[i-k]) flag = true;
        }

        if(flag) l = mid;
        else r = mid - 1;
    }

    cout << l;
}