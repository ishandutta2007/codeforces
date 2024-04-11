#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=20, t=10;
int n, m, q, szint[c], fel[c][k];
vector<int> sz[c], cs[c], ert[c][k];
bool v[c];
vector<int> unio(vector<int> a, vector<int> b) {
    vector<int> res;
    for (auto x:a) res.push_back(x);
    for (auto x:b) res.push_back(x);
    sort(res.begin(), res.end());
    while (res.size()>t) res.pop_back();
    return res;
}
void dfs(int a) {
    v[a]=true;
    ert[a][0]=cs[a];
    for (int i=1; i<k; i++) {
        int s=fel[a][i-1];
        fel[a][i]=fel[s][i-1];
        ert[a][i]=unio(ert[a][i-1], ert[s][i-1]);
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            fel[x][0]=a;
            szint[x]=szint[a]+1;
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        if (cs[x].size()<t) cs[x].push_back(i);
    }
    szint[1]=1;
    dfs(1);
    while (q--) {
        int x, y, cnt;
        cin >> x >> y >> cnt;
        vector<int> ans;
        if (szint[x]<szint[y]) swap(x, y);
        for (int i=k-1; i>=0; i--) {
            int s=fel[x][i];
            if (szint[s]>=szint[y]) {
                ans=unio(ans, ert[x][i]);
                x=s;
            }
        }
        for (int i=k-1; i>=0; i--) {
            int s=fel[x][i], t=fel[y][i];
            if (s!=t) {
                ans=unio(ans, ert[x][i]);
                ans=unio(ans, ert[y][i]);
                x=s, y=t;
            }
        }
        if (x!=y) {
            ans=unio(ans, ert[x][0]);
            ans=unio(ans, ert[y][0]);
            x=fel[x][0], y=fel[x][0];
        }
        ans=unio(ans, cs[x]);
        int si=min(cnt, (int)ans.size());
        cout << si << " ";
        for (int i=0; i<si; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}