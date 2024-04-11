#include <bits/stdc++.h>

using namespace std;
int m, n, p, db, x, t[8400001];
bool v[8400001];
void dfs(int a) {
    v[a]=true;
    if ((a>p || t[a]) && !v[t[a]]) dfs(t[a]);
    if (a<p) for (int i=0; i<m; i++) if (!(a&(1<<i)) && !v[a+(1<<i)]) dfs(a+(1<<i));
}
int main()
{
    ios_base::sync_with_stdio(false), ios_base::sync_with_stdio(false);
    cin >> m >> n, p=(1<<m);
    for (int i=1; i<=n; i++) cin >> x, t[p+i]=x, t[p-1-x]=p+i;
    for (int i=p+1; i<=p+n; i++) if (!v[i]) dfs(i), db++;
    cout << db << "\n";
    return 0;
}