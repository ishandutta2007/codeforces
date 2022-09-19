#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, si[c], diam;
vector<int> sz[c], spec;
vector<pair<int, int> > ans;
bool v[c], v2[c];
int dfs(int a) {
    v2[a]=true;
    int t1=0, t2=0;
    for (auto x:sz[a]) {
        if (!v2[x]) {
            t2=max(t2, dfs(x)+1);
            if (t2>t1) swap(t1, t2);
        }
    }
    diam=max(diam, t1+t2);
    return t1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    queue<int> q;
    for (int i=1; i<=n; i++) {
        si[i]=sz[i].size();
        if (si[i]<=1) {
            q.push(i);
        }
    }
    while (q.size()>0) {
        int a=q.front();
        q.pop();
        if (v[a]) continue;
        v[a]=true;
        if (si[a]==0) {
            spec.push_back(a);
        }
        for (auto x:sz[a]) {
            if (!v[x]) {
                si[x]--;
                if (si[x]<=1) {
                    q.push(x);
                }
            }
        }
    }
    for (int i=0; i<n-m-1; i++) {
        int a=spec[i], b=spec.back();
        ans.push_back({a, b});
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);

    cout << diam << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}