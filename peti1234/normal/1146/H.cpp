#include <bits/stdc++.h>

using namespace std;
const int c=302;
long long dp[c][c][7], n, x[c], y[c], sum;
vector<pair<long double, pair<int, int> > > el;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j) {
                el.push_back({atan2(x[i]-x[j], y[i]-y[j]), {i, j}});
            }
        }
    }
    sort(el.begin(), el.end());
    for (int i=1; i<=n; i++) {
        dp[i][i][1]=1;
    }
    for (auto s:el) {
        int a=s.second.first, b=s.second.second;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=5; j++) {
                dp[i][b][j+1]+=dp[i][a][j];
            }
        }
    }
    for (int i=1; i<=n; i++) {
        sum+=dp[i][i][6];
    }
    cout << sum << "\n";
    return 0;
}