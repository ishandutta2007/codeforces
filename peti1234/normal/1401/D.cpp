#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long w, n, m, mod=1e9+7, rf[c], sum;
bool v[c];
vector<long long> pr, el;
vector<int> sz[c];
void dfs(int a) {
    v[a]=true, rf[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) dfs(x), rf[a]+=rf[x];
    }
    if (a!=1) el.push_back(rf[a]*(n-rf[a]));
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, sum=0, pr.clear(), el.clear();
        for (int i=1; i<=n; i++) rf[i]=0, sz[i].clear(), v[i]=0;
        for (int i=1; i<n; i++) {
            int a, b; cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        cin >> m;
        for (int i=0; i<m; i++) {
            int x; cin >> x;
            pr.push_back(x);
        }
        for (int i=1; i<n-m; i++) pr.push_back(1);
        sort(pr.begin(), pr.end()), sort(el.begin(), el.end());
        while(pr.size()>=n) {
            long long x=pr.back();
            pr.pop_back(), pr.back()*=x, pr.back()%=mod;
        }
        for (int i=0; i<n-1; i++) sum+=el[i]*pr[i], sum%=mod;
        cout << sum << "\n";
    }
    return 0;
}