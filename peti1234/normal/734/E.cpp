#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, maxi;
vector<int> sz[c];
bool v[c], cl[c];
int dfs(int a) {
    v[a]=true;
    int p=0, q=0;
    for (int x:sz[a]) {
        if (!v[x]) {
            int z=dfs(x);
            if (cl[a]!=cl[x]) z++;
            q=max(q, z);
            if (q>p) swap(p, q);
        }
    }
    maxi=max(maxi, q+p);
    return p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> cl[i];
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << (maxi+1)/2 << "\n";
    return 0;
}