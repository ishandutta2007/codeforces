#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, ans, l[c], r[c], sum[c];
vector<int> sz[c];
void dfs(int a) {
    for (auto x:sz[a]) {
        dfs(x);
        sum[a]+=sum[x];
    }
    sum[a]=min(sum[a], r[a]);
    if (sum[a]<l[a]) {
        ans++;
        sum[a]=r[a];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=2; i<=n; i++) {
            int x;
            cin >> x;
            sz[x].push_back(i);
        }
        for (int i=1; i<=n; i++) {
            cin >> l[i] >> r[i];
        }
        dfs(1);
        //cout << "valasz............... ";
        cout << ans << "\n";
        ans=0;
        for (int i=1; i<=n; i++) {
            sum[i]=0;
            sz[i].clear();
        }
    }
    return 0;
}