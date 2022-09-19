#include <bits/stdc++.h>

using namespace std;
const int c=1050002;
int n, m, f[c], l[c], fsz, lsz, mask[c];
vector<int> sz[c];
bool v[c];
int dfs(int a) {
    int ans=0;
    if (l[a]!=-1) ans+=1<<l[a];
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            ans+=dfs(x);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b);
        l[a]=-1, f[b]=-1;
    }
    for (int i=1; i<=n; i++) {
        if (!l[i]) {
            l[i]=lsz, lsz++;
        }
        if (!f[i]) {
            f[i]=fsz, fsz++;
        }
    }
    for (int i=1; i<=n; i++) {
        if (f[i]!=-1) {
            for (int j=1; j<=n; j++) v[j]=0;
            mask[1<<f[i]]=dfs(i);
        }
    }
    for (int i=1; i<(1<<fsz)-1; i++) {
        int x=(i&(-i));
        mask[i]=mask[i-x]|mask[x];
        if (__builtin_popcount(i)>=__builtin_popcount(mask[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}