#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, k, ert, si[c], ans[c];
vector<pair<int, int> > sz[c];
vector<int> p;
bool v[c];
void dfs(int a, int b) {
    v[a]=true;
    int cnt=1;
    if (si[a]<=ert && b==1) cnt++;
    for (auto s:sz[a]) {
        int x=s.first, y=s.second;
        if (!v[x]) {
            ans[y]=cnt;
            dfs(x, cnt);
            if (si[a]<=ert) cnt++;
            if (si[a]<=ert && cnt==b) cnt++;
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
        sz[a].push_back({b, i}), sz[b].push_back({a, i});
    }
    for (int i=1; i<=n; i++) {
        si[i]=sz[i].size();
        p.push_back(si[i]);
    }
    sort(p.rbegin(), p.rend());
    ert=p[k];
    dfs(1, 0);
    cout << ert << "\n";
    for (int i=1; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}