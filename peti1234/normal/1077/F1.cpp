#include <bits/stdc++.h>
 
using namespace std;
const int c=5005;
long long n, k, x, t[c], dp[c][c], sok=1e15, ans=-1;
deque<int> q;
int main()
{   
    cin >> n >> k >> x;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        dp[0][i]=-sok;
    }
    for (int i=1; i<=x; i++) {
        
        q.push_front(0);
        for (int j=1; j<=n; j++) {
            dp[i][j]=dp[i-1][q.back()]+t[j];
            if (j-k==q.back()) {
                q.pop_back();
            }
            while (q.size()>0 && dp[i-1][j]>=dp[i-1][q.front()]) {
                q.pop_front();
            }
            q.push_front(j);
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
        q.clear();
    }
    for (int i=n-k+1; i<=n; i++) {
        ans=max(ans, dp[x][i]);
    }
    cout << ans << "\n";
    return 0;
}