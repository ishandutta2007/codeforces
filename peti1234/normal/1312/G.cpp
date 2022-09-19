#include <bits/stdc++.h>

using namespace std;
const int c=1000005, p=27;
int n, k, kov[c][p], fel[c], ans[c], rf[c], t[c];
bool v[c];
void dfs(int a, int ert) {
    //cout << "dfs " << a << " " << ert << " " << fel[a] << "\n";
    if (v[a]) {
        ans[a]=min(ans[a], ert);
        ert=min(ans[a]+1, ert)+1;
        rf[a]=1;
    } else {
        ert=min(ert, ans[a]+1);
    }
    for (int i=1; i<p; i++) {
        int s=kov[a][i];
        if (s) {
            ans[s]=ans[a]+1;
            dfs(s, ert);
            ert+=rf[s];
            rf[a]+=rf[s];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        char c;
        int s, x;
        cin >> x >> c;
        s=(c-'a'+1);
        kov[x][s]=i, fel[i]=x;
    }
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> t[i];
        v[t[i]]=1;
    }
    dfs(0, 1);
    for (int i=1; i<=k; i++) {
        cout << ans[t[i]] << " ";
    }
    cout << "\n";
    return 0;
}