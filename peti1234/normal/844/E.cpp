#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, f[c], rf[c], h, l, ki, ut;
vector<int> sz[c];
vector<pair<int, pair<int, int> > > sol;
bool v1[c], v2[c], cen[c];
void add(int x, int y1, int y2) {sol.push_back({x, {y1, y2}});}
void dfs1(int a) {
    v1[a]=true, rf[a]=1;
    int maxi=0;
    for (int x:sz[a]) if (!v1[x]) {
        dfs1(x);
        maxi=max(maxi, rf[x]);
        rf[a]+=rf[x];
    }
    if (rf[a]>=h && n-maxi>=h) cen[a]=1, v2[a]=1;
}
void dfs3(int a) {
    v2[a]=true;
    for (int x:sz[a]) if (!v2[x]) f[x]=a, dfs3(x), add(l, ut, x), add(x, a, ki), ut=x;
}
void dfs2(int a) {
    v2[a]=true;
    for (int x:sz[a]) if (!v2[x]) f[x]=a, l=a, ki=x, ut=x, dfs3(x), add(a, ut, x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    h=(n+1)/2, dfs1(1);
    for (int i=1; i<=n; i++) if (cen[i]) dfs2(i);
    int si=sol.size();
    cout << si << "\n";
    for(int i=0; i<si; i++) cout << sol[i].first << " " << sol[i].second.first << " " << sol[i].second.second << "\n";
    return 0;
}