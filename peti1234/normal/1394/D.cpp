#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, t[c], h[c], fel[c], le[c], s[c], ans, add, si, f, l, u, p, q;
bool v[c];
vector<int> sz[c], d[c];
void dfs(int a) {
    v[a]=true;
    long long kis=0, nagy=0, sum=0;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        kis+=(h[x]>h[a]), nagy+=(h[a]>h[x]);
        if (!v[x] && h[a]==h[x]) dfs(x), sum+=fel[x], d[a].push_back(le[x]-fel[x]);
    }
    si=d[a].size(), u=1e18, f=1e18, l=1e18, add=0;
    sort(d[a].begin(), d[a].end());
    for (int i=0; i<si; i++) {
        p=kis+i, q=nagy+si-i;
        f=min(f, add+max(p+1, q)*t[a]);
        l=min(l, add+max(p, q+1)*t[a]);
        u=min(u, add+max(p, q)*t[a]);
        add+=d[a][i];
    }
    p=kis+si, q=nagy;
    f=min(f, add+max(p+1, q)*t[a]);
    l=min(l, add+max(p, q+1)*t[a]);
    u=min(u, add+max(p, q)*t[a]);
    fel[a]=f+sum, le[a]=l+sum, s[a]=u+sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=n; i++) cin >> h[i];
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) if (!v[i]) dfs(i), ans+=s[i];
    cout << ans << "\n";
    return 0;
}