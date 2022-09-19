#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long t[c], kezd[c], veg[c], mini[c], poz[c], neg[c], dp[c], sum, n;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    if (kezd[a] && !veg[a]) neg[a]++;
    if (!kezd[a] && veg[a]) poz[a]++;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            mini[x]=min(t[x], mini[a]);
            dfs(x);
            poz[a]+=poz[x], neg[a]+=neg[x], dp[a]+=dp[x];
        }
    }
    long long sm=min(poz[a], neg[a]);
    dp[a]+=mini[a]*sm*2, poz[a]-=sm, neg[a]-=sm;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i] >> kezd[i] >> veg[i];
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    mini[1]=t[1], dfs(1);
    if (poz[1] || neg[1]) cout << -1 << "\n";
    else cout << dp[1] << "\n";
    return 0;
}