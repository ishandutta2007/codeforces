#include <bits/stdc++.h>

using namespace std;
const int c=200002, f=102;
int n, m, k, p[11], ans, v[c][f];
vector<pair<int, int> > sz[c];
bool t[f][f];
vector<int> van;
void solve(int a) {
    if (a==0) return;
    if (a>k) {ans++; return;}
    p[a+1]=0;
    if (p[a]==a) {solve(a-1); return;}
    p[a]++;
    for (int i=1; i<=a; i++) if (t[10*i+p[i]][10*a+p[a]]) {solve(a); return;}
    solve(a+1);
    if (p[a]) solve(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz[a].push_back({c, b});
    }
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end());
        int si=sz[i].size();
        for (int j=0; j<si; j++) {
            int x=sz[i][j].second;
            v[x][10*si+j+1]++;
        }
    }
    for (int i=1; i<=n; i++) {
        van.clear();
        for (int j=1; j<f; j++) {
            if (v[i][j]) van.push_back(j);
            if (v[i][j]>1) van.push_back(j);
        }
        int si=van.size();
        for (int i=0; i<si; i++) for (int j=i+1; j<si; j++) t[van[i]][van[j]]=1, t[van[j]][van[i]]=1;
    }
    solve(1);
    cout << ans << "\n";
    return 0;
}