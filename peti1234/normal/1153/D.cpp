#include <bits/stdc++.h>

using namespace std;
int n;
int l;
bool v[300001];
int res[300001];
vector<int> sz[300001];
void solve(int a)
{
    if (sz[a].size()==0) {
        res[a]=1;
        l++;
        return;
    }
    if (v[a]==1) {
        res[a]=INT_MAX;
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        solve(x);
        if (v[a]==1) {
            res[a]=min(res[a], res[x]);
        } else {
            res[a]+=res[x];
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=2; i<=n; i++) {
        int x;
        cin >> x;
        sz[x].push_back(i);
    }
    solve(1);
    cout << l-res[1]+1 << endl;
    return 0;
}