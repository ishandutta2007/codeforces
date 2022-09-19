#include <bits/stdc++.h>

using namespace std;
long long n, dp[200005][10], sok=1e15;
vector<int> sz[4];
int main()
{
    cin >> n;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<10; j++) {
            dp[i][j]=-sok;
        }
    }
    dp[0][0]=0;
    for (int i=1; i<=n; i++) {
        int m;
        cin >> m;
        for (int j=1; j<=m; j++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b);
        }
        for (int j=1; j<=3; j++) sort(sz[j].rbegin(), sz[j].rend());
        vector<vector<long long> > p;
        int e=sz[1].size(), k=sz[2].size(), h=sz[3].size();
        p.push_back({});
        if (e) p.push_back({sz[1][0]});
        if (k) p.push_back({sz[2][0]});
        if (h) p.push_back({sz[3][0]});
        if (e && k) p.push_back({sz[1][0], sz[2][0]});
        if (e>=2) p.push_back({sz[1][0], sz[1][1]});
        if (e>=3) p.push_back({sz[1][0], sz[1][1], sz[1][2]});

        for (int j=0; j<p.size(); j++) sort(p[j].begin(), p[j].end());

        for (auto x:p) {
            long long si=x.size(), sum=0, maxi=0;
            for (auto y:x) sum+=y, maxi=max(maxi, y);
            for (int el=0; el<10; el++) {
                int kov=(el+si)%10;
                long long add=(el+si>=10 ? maxi : 0);
                dp[i][kov]=max(dp[i][kov], dp[i-1][el]+sum+add);
            }
        }

        /*for (int j=0; j<10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";*/

        for (int j=1; j<=3; j++) sz[j].clear();
    }
    long long ans=0;
    for (int i=0; i<10; i++) {
        ans=max(ans, dp[n][i]);
    }
    cout << ans << "\n";
    return 0;
}