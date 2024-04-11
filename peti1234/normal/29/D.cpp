#include <bits/stdc++.h>

using namespace std;
const int c=302;
int n, pos=1, db;
vector<int> sz[c], sol;
bool v[c];
bool dfs(int a, int b) {
    v[a]=true;
    if (a==b) {
        return true;
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            if (dfs(x, b)) {
                sol.push_back(a);
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=2; i<=n; i++) {
        if (sz[i].size()==1) db++;
    }
    sol.push_back(1);
    for (int i=1; i<=db; i++) {
        int x; cin >> x;
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
        dfs(x, pos);
        pos=x;
    }
    for (int i=1; i<=n; i++) {
        v[i]=0;
    }
    dfs(1, pos);
    if (sol.size()!=2*n-1) cout << -1 << "\n";
    else {
        for (int i:sol) cout << i << " ";
        cout << "\n";
    }
    return 0;
}