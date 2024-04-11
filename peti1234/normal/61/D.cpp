#include <bits/stdc++.h>

using namespace std;
const int c=100002;
vector<int> sz[c], s[c];
long long n, dist[c], sum, maxi;
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) dist[x]=dist[a]+s[a][i], dfs(x);
    }
    maxi=max(maxi, dist[a]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c, sum+=2*c;
        sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(c), s[b].push_back(c);
    }
    dfs(1);
    cout << sum-maxi << "\n";
    return 0;
}