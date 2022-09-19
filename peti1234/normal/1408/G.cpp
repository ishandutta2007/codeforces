#include <bits/stdc++.h>

using namespace std;
const int c=1502;
long long mod=998244353, dp[c][c];
int el[c][c], inv[c][c], f[c], db[c], ki[c], n, cnt=0;
bool v[c], h[c], kesz;
vector<pair<int, int>> sz[c];
vector<int> jo[c];
priority_queue<pair<int, pair<int, int>>> q;
void dfs(int a, int b) {
    if (!v[a]) v[a]=1, cnt++;
    if (a<b) {
        kesz=1;
        for (int i=0; i<jo[a].size(); i++) if (jo[a][i]>=inv[a][b]) jo[b].push_back(jo[a][i]);
        return;
    }
    while(f[a]+1<=cnt) {
        f[a]++;
        int x=sz[a][f[a]].second;
        if (!v[x]) {
            dfs(x, b);
            if (kesz) return;
        }
        if (f[a]==cnt && a==b) {
            for (int i=1; i<=cnt; i++) {
                int x=sz[a][i].second;
                if (f[x]!=cnt) dfs(x, b);
            }
        }
        if (f[a]==cnt && a==b) {
            jo[b].push_back(cnt);
            if (cnt<n) {
                dfs(sz[a][cnt+1].second, b);
                if (kesz) return;
            }
        }
    }
}
void unio(int a, int b) {
    h[b]=1;
    int sb=0, sa=0, st=0;
    for (int i=1; i<=n; i++) {
        if (dp[b][i]) sb=i;
        if (dp[a][i]) sa=i;
        if (dp[a][i] && !st) st=i;
    }
    for (int i=sa+sb; i>=1; i--) {
        dp[a][i]=0;
        for (int j=1; j<=min(i, sb); j++) {
            dp[a][i]+=dp[a][i-j]*dp[b][j];
            dp[a][i]%=mod;
        }
    }
    for (int i=1; i<st; i++) dp[a][i]=0;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        sz[i].push_back({-1, 0});
        for (int j=1; j<=n; j++) {
            int x; cin >> x;
            sz[i].push_back({x, j});
        }
        sort(sz[i].begin(), sz[i].end());
        for (int j=1; j<=n; j++) inv[i][sz[i][j].second]=j;
    }
    if (n==1) {
        cout << 1 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        cnt=0, kesz=0;
        for (int j=1; j<=n; j++) v[j]=0, f[j]=0;
        dfs(i, i);
        dp[i][1]=1, q.push({1-jo[i][1], {i, 0}});
    }
    while(q.size()>0) {
        int tav=-q.top().first, id=q.top().second.first, pos=q.top().second.second, db=jo[id][pos];
        q.pop();
        if (!h[id]) {
            for (int i=db+1; i<=db+tav; i++) {
                int x=sz[id][i].second;
                if (!h[x]) unio(id, x);
            }
            dp[id][1]=1;
            if (tav+db<n) {
                q.push({tav+db-jo[id][pos+2], {id, pos+1}});
            } else {
                for (int i=1; i<=n; i++) cout << dp[id][i] << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}