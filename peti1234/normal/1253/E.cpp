#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m, dp[c];
vector<pair<int, int> > sz;
bool v[c];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        dp[i]=i;
    }
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j=max(1, a-b); j<=min(m, a+b); j++) {
            v[j]=true;
        }
        sz.push_back({a, b});
    }
    for (int i=1; i<=m; i++) {
        dp[i]=min(dp[i], dp[i-1]+1-v[i]);
        for (int j=0; j<n; j++) {
            int a=sz[j].first, b=sz[j].second;
            if (a>i && a-b>i) {
                int c=a-b-i;
                int d=min(m, a+b+c);
                dp[d]=min(dp[d], dp[i-1]+c);
            }
        }
    }
    cout << dp[m] << "\n";
    return 0;
}