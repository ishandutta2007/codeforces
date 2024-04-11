#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, rossz[c], ans[c], maxi[c];
bool kesz[c];
priority_queue<pair<int, int> > q;
vector<int> sz[c], inv[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        if (a==n) continue;
        rossz[a]++;
        sz[a].push_back(b), inv[b].push_back(a);
    }
    for (int i=1; i<n; i++) {
        ans[i]=c;
    }
    q.push({0, n});
    while (q.size()>0) {
        int a=q.top().second;
        q.pop();
        if (kesz[a]) continue;
        kesz[a]=1;
        for (auto x:inv[a]) {
            rossz[x]--;
            maxi[x]=ans[a]+1;
            if (maxi[x]+rossz[x]<ans[x]) {
                ans[x]=maxi[x]+rossz[x];
                q.push({-ans[x], x});
            }
        }
    }
    cout << ans[1] << "\n";
    return 0;
}