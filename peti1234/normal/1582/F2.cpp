#include <bits/stdc++.h>

using namespace std;
const int c=8192;
int dp[c], n, x, cnt;
vector<int> sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        dp[i]=5001;
        sz[i].push_back(i);
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (auto y:sz[x]) {
            while (dp[y]>x) {
                sz[dp[y]].push_back(y^dp[y]);
                dp[y]--;
            }
        }
        sz[x].clear();
    }
    for (int i=0; i<c; i++) {
        if (dp[i]<=5000) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i=0; i<c; i++) {
        if (dp[i]<=5000) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}