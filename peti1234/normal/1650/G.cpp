#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, m, kezd, veg, szint[c], dp[c][2], mod=1e9+7;
vector<int> sz[c], p[c];
queue<int> q;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> m >> kezd >> veg;
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        q.push(kezd);
        v[kezd]=1;
        while (q.size()>0) {
            int a=q.front();
            q.pop();
            //cout << "fontos " << a << " " << szint[a] << "\n";
            p[szint[a]].push_back(a);
            p[szint[a]+1].push_back(a);
            for (auto x:sz[a]) {
                if (!v[x]) {
                    v[x]=1;
                    szint[x]=szint[a]+1;
                    q.push(x);
                }
            }
        }

        dp[kezd][0]=1;
        for (int i=0; i<=szint[veg]; i++) {
            for (auto a:p[i]) {
                int s=szint[a], ert=dp[a][(i==s ? 0 : 1)];
                for (auto x:sz[a]) {
                    if (szint[x]==i) {
                        dp[x][1]=(dp[x][1]+ert);
                        if (dp[x][1]>=mod) dp[x][1]-=mod;
                    }
                    if (szint[x]==i+1) {
                        dp[x][0]=(dp[x][0]+ert);
                        if (dp[x][0]>=mod) dp[x][0]-=mod;
                    }
                }
            }
        }
        //cout << "valasz................. ";
        cout << (dp[veg][0]+dp[veg][1])%mod << "\n";

        for (int i=0; i<=n+1; i++) {
            p[i].clear();
            sz[i].clear();
            dp[i][0]=0, dp[i][1]=0, v[i]=0, szint[i]=0;
        }
    }
    return 0;
}
/*
1
2 1
1 2
1 2
*/