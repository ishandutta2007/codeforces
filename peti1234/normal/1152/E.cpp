#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, sor[c], aa[c], bb[c], s[c], cnt, kezd;
vector<pair<int, int> > sz[c];
vector<int> ans;
map<int, int> m;
stack<int> q;
bool h[c];
int ki(int a) {
    if (m.find(a)==m.end()) {
        m[a]=++cnt;
        sor[cnt]=a;
    }
    return m[a];
}

void dfs(int a) {
    q.push(a);
    while (s[a]<sz[a].size()) {
        int kov=sz[a][s[a]].first, id=sz[a][s[a]].second;
        s[a]++;
        if (!h[id]) {
            h[id]=1;
            dfs(kov);
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        cin >> aa[i];
    }
    for (int i=1; i<n; i++) {
        cin >> bb[i];
        int x=ki(aa[i]), y=ki(bb[i]);
        if (bb[i]>=aa[i]) {
            sz[x].push_back({y, i}), sz[y].push_back({x, i});
        }
    }
    kezd=1;
    for (int i=1; i<=cnt; i++) {
        if (sz[i].size()%2) {
            kezd=i;
        }
    }
    dfs(kezd);
    while (q.size()>0) {
        int id=q.top();
        ans.push_back(id);
        q.pop();
        dfs(id);
        if (q.top()!=id) {
            cout << -1 << "\n";
            return 0;
        }
        q.pop();
    }
    if (ans.size()!=n) {
        cout << -1 << "\n";
    } else {
        for (auto x:ans) {
            cout << sor[x] << " ";
        }
        cout << "\n";
    }
    return 0;
}