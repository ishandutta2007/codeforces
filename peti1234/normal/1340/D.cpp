#include <bits/stdc++.h>

using namespace std;
vector<int> sz[100002];
int n, maxi;
bool v[100002];
vector<pair<int, int> > sol;
void dfs(int a, int b) {
    int si=sz[a].size(), f=0;
    v[a]=1, cout << a << " " << b << "\n";
    for (int i=0; i<si; i++) {
        int x=sz[a][i];
        if (!v[x]) {
            if (b>=si && !f) b-=si, f++, cout << a << " " << b << "\n";
            b++, dfs(x, b), cout << a << " " << b << "\n";
        }
     }
    if (a!=1 && b>=si && !f) b-=si, cout << a << " " << b << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    cout << 3*n-2 << "\n";
    for (int i=1; i<=n; i++) maxi=max(maxi, (int)sz[i].size());
    dfs(1, 0);

    return 0;
}