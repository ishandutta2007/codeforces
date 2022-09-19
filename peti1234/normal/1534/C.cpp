#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int w, n, t1[c], t2[c], ki[c];
long long ans, mod=1e9+7;
bool v[c];
void dfs(int a) {
    v[a]=true;
    if (!v[ki[a]]) {
        dfs(ki[a]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t1[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> t2[i];
            ki[t1[i]]=t2[i];
        }
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
        ans=1;
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                ans*=2;
                ans%=mod;
                dfs(i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}