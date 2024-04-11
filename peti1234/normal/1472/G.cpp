#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, m, tav[c], dp[c][2];
vector<int> sz[c];
vector<pair<int, int> > sor;
bool v[c];
queue<pair<int, int> > q;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        sor.clear();
        for (int i=1; i<=n; i++) {
            sz[i].clear();
            v[i]=0;
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b);
        }
        for (int i=2; i<=n; i++) {
            tav[i]=n;
        }
        q.push({1, 0});
        while(q.size()>0) {
            int a=q.front().first, b=q.front().second;
            q.pop();
            if (!v[a]) {
                v[a]=true, tav[a]=b;
                for (int i=0; i<sz[a].size(); i++) {
                    int x=sz[a][i];
                    if (!v[x]) {
                        q.push({x, b+1});
                    }
                }
            }
        }
        for (int i=2; i<=n; i++) {
            sor.push_back({tav[i], i});
        }
        int si=sor.size();
        sort(sor.begin(), sor.end());
        for (int i=1; i<=n; i++) {
            dp[i][0]=tav[i];
        }
        for (int i=si-1; i>=0; i--) {
            int id=sor[i].second;
            for (int j:sz[id]) {
                if (tav[j]>tav[id]) {
                    dp[id][0]=min(dp[id][0], dp[j][0]);
                }
            }
        }
        for (int i=0; i<si; i++) {
            int id=sor[i].second;
            dp[id][1]=dp[id][0];
            for (int j:sz[id]) {
                dp[id][1]=min(dp[id][1], dp[j][0]);
            }
        }
        for (int i=si-1; i>=0; i--) {
            int id=sor[i].second;
            for (int j:sz[id]) {
                if (tav[j]>tav[id]) {
                    dp[id][1]=min(dp[id][1], dp[j][1]);
                }
            }
        }
        for (int i=1; i<=n; i++) {
            cout << dp[i][1] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
1
6 8
1 2
1 5
2 6
6 1
2 3
3 4
4 2
5 4




*/