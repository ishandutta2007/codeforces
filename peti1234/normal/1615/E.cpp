#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, k, f[c], dist[c], ch[c];
vector<int> sz[c];
bool v[c], h[c];
priority_queue<pair<int, int> > q;
void dfs(int a) {
    v[a]=true;
    dist[a]=1, ch[a]=a;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            f[x]=a;
            if (dist[x]+1>dist[a]) {
                dist[a]=dist[x]+1;
                ch[a]=ch[x];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    q.push({dist[1], ch[1]});
    int p=n;
    long long ans=-1e12;
    for (int i=1; i<=k; i++) {
        if (q.size()>0) {
            auto s=q.top();
            q.pop();
            p-=s.first;
            int cs=s.second;
            for (int i=0; i<s.first; i++) {
                for (auto x:sz[cs]) {
                    if (!h[x] && x!=f[cs]) {
                        q.push({dist[x], ch[x]});
                    }
                }
                h[cs]=1;
                cs=f[cs];
            }
        }
        long long ert=min(p, n/2);
        ans=max(ans, (i-ert)*(n-i-ert));
    }
    cout << ans << "\n";
    return 0;
}