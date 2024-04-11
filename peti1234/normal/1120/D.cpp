#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long t[c], sum[c], ln[c], lnpos[c];
int n, cnt;
vector<int> sz[c], sol;
bool v[c], v2[c];
void dfs(int a) {
    v[a]=true;
    if (sz[a].size()==1 && a!=1) {
        sum[a]=ln[a]=t[a];
        cnt++;
        return;
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            sum[a]+=sum[x];
            if (ln[x]==ln[a]) {
                lnpos[a]=0;
            }
            if (ln[x]>ln[a]) {
                ln[a]=ln[x];
                lnpos[a]=x;
            }
        }
    }
    if (ln[a]>=t[a]) {
        sum[a]-=ln[a]-t[a];
        ln[a]=t[a];
    }
}
void solve(int a, int b) {
    v2[a]=true;
    if (!b && t[a]<=ln[a]) {
        sol.push_back(a);
        if (t[a]!=ln[lnpos[a]]) {
            b=1;
        }
    }
    for (int x:sz[a]) {
        if (!v2[x]) {
            solve(x, (b==1 && lnpos[a]==x));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << sum[1] << " ";
    solve(1, 0);
    cout << sol.size() << "\n";
    sort(sol.begin(), sol.end());
    for (int i:sol) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}