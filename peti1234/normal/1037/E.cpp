#include <bits/stdc++.h>

using namespace std;
int n, m, k;
vector<pair<int, int> > p;
vector<int> sz[200001];
vector<int> tor[200001];
int f[200001];
bool v[200001];
int r;
vector<int> ans;
void jo(int a)
{
    if (f[a]>=k || !v[a]) {
        return;
    }
    v[a]=false;
    f[a]=0;
    r--;
    for (int i=0; i<tor[a].size(); i++) {
        int x=tor[a][i];
        if (v[x]) {
            f[x]++;
        }
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (v[x]) {
            f[x]--;
            if (f[x]<k) {
                jo(x);
            }
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    r=n;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        v[i]=true;
        f[i]=sz[i].size();
    }
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            jo(i);
        }
    }
    reverse(p.begin(), p.end());
    for (int i=0; i<m; i++) {
        /*for (int i=1; i<=n; i++) {
            cout << f[i] << " ";
        }
        cout << endl;*/
        ans.push_back(r);
        int x=p[i].first;
        int y=p[i].second;
        if (v[x] && v[y]) {
            f[x]--;
            f[y]--;
            tor[x].push_back(y);
            tor[y].push_back(x);
            jo(x);
            jo(y);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i=0; i<m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}