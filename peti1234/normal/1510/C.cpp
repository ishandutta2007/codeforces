#include <bits/stdc++.h>

using namespace std;
const int c=100108;
int n, m;
vector<int> sz[c], sz2[c];
set<pair<int, int> > el;
int cnt, eler[c], visz[c], f[c];
bool v2[c], v[c];
vector<pair<int, int> > ans;
void dfs2(int a) {
    cnt++;
    v2[a]=true;
    eler[a]=cnt, visz[a]=cnt;
    for (int x:sz2[a]) {
        if (!v2[x]) {
            f[x]=a;
            dfs2(x);
            visz[a]=min(visz[a], visz[x]);
            if (eler[a]<visz[x]) {
                sz[a].push_back(x), sz[x].push_back(a);
            }
        } else {
            if (x!=f[a]) {
                visz[a]=min(visz[a], eler[x]);
            }
        }
    }
}
int dfs(int a) {
    v[a]=true;
    int el=0, si=sz[a].size();
    bool spec=false;
    for (int x:sz[a]) {
        if (!v[x]) {
            int s=dfs(x);
            if (!s && (spec || si%2==0)) {
                s=x;
            }
            if (!s) {
                spec=1;
            } else {
                if (el) {
                    ans.push_back({el, s});
                    el=0;
                } else {
                    el=s;
                }
            }
        }
    }
    return el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    while (true) {
        cin >> n >> m;
        if (n==0) {
            break;
        }
        for (int i=1; i<=m; i++) {
            int h, pr, x;
            cin >> h >> pr;
            for (int j=1; j<h; j++) {
                cin >> x;
                if (pr>x) {
                    el.insert({x, pr});
                } else {
                    el.insert({pr, x});
                }
                pr=x;
            }
        }
        for (auto x:el) {
            int a=x.first, b=x.second;
            sz2[a].push_back(b), sz2[b].push_back(a);
        }
        dfs2(1);
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                int s=dfs(i);
                if (s) {
                    ans.push_back({s, i});
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
        for (int i=1; i<=n; i++) {
            sz[i].clear(), sz2[i].clear();
            v[i]=0, v2[i]=0, f[i]=0, eler[i]=0, visz[i]=0;
        }
        el.clear(), ans.clear();
        cnt=0;
    }
    return 0;
}