#include <bits/stdc++.h>

using namespace std;
const int c=500002, mod=998244353;
long long n, sum[c], db[c], np[c], vp[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            sum[a]=(sum[a]*db[x]+db[a]*sum[x]+np[a]*np[x])%mod;
            np[a]=np[a]*(db[x]-np[x]+mod)%mod;
            db[a]=db[a]*db[x]%mod;
        }
    }
    sum[a]*=2, db[a]*=2;
    sum[a]%=mod, db[a]%=mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) db[i]=1, np[i]=1;
    dfs(1);
    cout << sum[1] << "\n";
    return 0;
}