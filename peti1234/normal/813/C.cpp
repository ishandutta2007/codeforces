#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, pos, szint[c], fel[c], maxi[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    maxi[a]=szint[a];
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a;
            dfs(x);
            maxi[a]=max(maxi[a], maxi[x]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> pos;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    int cel=szint[pos]/2+1;
    while (szint[pos]>cel) pos=fel[pos];
    cout << 2*maxi[pos] << "\n";
    return 0;

}