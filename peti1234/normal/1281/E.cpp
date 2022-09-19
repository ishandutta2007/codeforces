#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, mini, maxi, rf[c];
vector<pair<int, long long> > sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    rf[a]=1;
    for (auto p:sz[a]) {
        int x=p.first;
        long long suly=p.second;
        if (!v[x]) {
            dfs(x);
            if (rf[x]%2) {
                mini+=suly;
            }
            maxi+=suly*min(rf[x], n-rf[x]);
            rf[a]+=rf[x];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        n*=2;
        for (int i=1; i<n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            sz[a].push_back({b, c});
            sz[b].push_back({a, c});
        }
        dfs(1);
        cout << mini << " " << maxi << "\n";
        mini=0, maxi=0;
        for (int i=1; i<=n; i++) {
            rf[i]=0, v[i]=0;
            sz[i].clear();
        }
    }
    return 0;
}