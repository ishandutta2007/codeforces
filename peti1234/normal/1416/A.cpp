#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, mini, maxi[c];
vector<int> sz[c], pos[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, mini=n+1;
        for (int i=1; i<=n; i++) sz[i].clear(), pos[i].clear(), pos[i].push_back(0), maxi[i]=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            maxi[x]=max(maxi[x], i-pos[x].back());
            pos[x].push_back(i);
        }
        for (int i=1; i<=n; i++) {
            maxi[i]=max(maxi[i],  n+1-pos[i].back());
            sz[maxi[i]].push_back(i);
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<sz[i].size(); j++) mini=min(mini, sz[i][j]);
            if (mini>n) cout << "-1 ";
            else cout << mini << " ";
        }
        cout << "\n";
    }
    return 0;
}