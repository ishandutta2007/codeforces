#include <bits/stdc++.h>

using namespace std;
vector<int> sz[200002], ans;
int t[200002], rf[200002], n, k;
long long sum;
bool v[200002];
void dfs(int a) {
    v[a]=true, rf[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            t[x]=t[a]+1;
            dfs(x);
            rf[a]+=rf[x];
        }
    }
    ans.push_back(t[a]-rf[a]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    sort(ans.rbegin(), ans.rend());
    for (int i=0; i<k; i++) sum+=ans[i];
    cout << sum+k << "\n";
    return 0;
}