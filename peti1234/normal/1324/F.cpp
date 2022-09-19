#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, t[c], maxi[c];
vector<int> sz[c];
bool v1[c], v2[c];
void dfs1(int a) {
    v1[a]=true;
    if (t[a]) maxi[a]=1;
    else maxi[a]=-1;
    for (int x:sz[a]) {
        if (!v1[x]) {
            dfs1(x);
            maxi[a]+=max(0, maxi[x]);
        }
    }
}
void dfs2(int a) {
    v2[a]=true;
    for (int x:sz[a]) {
        if (!v2[x]) {
            if (maxi[x]<0) maxi[x]=max(maxi[x], maxi[a]-1);
            else maxi[x]=max(maxi[x], maxi[a]);
            dfs2(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs1(1);
    dfs2(1);
    for (int i=1; i<=n; i++) {
        cout << maxi[i] << " ";
    }
    cout << "\n";
    return 0;
}