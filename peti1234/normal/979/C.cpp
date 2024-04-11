#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long n, p, q, rp, rq, sum, rf[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    rf[a]=1, v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) dfs(x), rf[a]+=rf[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> q;
    for (int i=1; i<n; i++) {int a, b; cin >> a >> b; sz[a].push_back(b), sz[b].push_back(a);}
    sum=(n-1)*n;
    dfs(p), rq=rf[q];
    for (int i=1; i<=n; i++) v[i]=0, rf[i]=0;
    dfs(q), rp=rf[p];
    cout << sum-rp*rq;
    return 0;
}