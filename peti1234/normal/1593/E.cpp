#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int w, n, k, si[c];
vector<int> sz[c];
bool v[c];
vector<int> regi, uj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        for (int i=1; i<=n; i++) {
            si[i]=sz[i].size();
            if (si[i]<=1) {
                regi.push_back(i);
            }
        }
        for (int i=1; i<=k; i++) {
            if (regi.size()==0) {
                break;
            }
            for (auto x:regi) {
                if (v[x]) {
                    continue;
                }
                v[x]=1;
                for (auto y:sz[x]) {
                    si[y]--;
                    if (si[y]<=1 && !v[y]) {
                        uj.push_back(y);
                    }
                }
            }
            regi.clear();
            swap(regi, uj);
        }
        int ans=0;
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                ans++;
            }
        }
        cout << ans << "\n";

        for (int i=1; i<=n; i++) {
            v[i]=0, si[i]=0;
            sz[i].clear();
        }
        regi.clear(), uj.clear();
    }
    return 0;
}