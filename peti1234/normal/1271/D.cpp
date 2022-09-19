#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int n, m, k, fel[c], mini[c], ert[c], ut[c], ans;
bool baj=0;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        ut[i]=i;
        int sz, pl;
        cin >> sz >> pl >> ert[i];
        fel[i]=k-sz;
        if (fel[i]<0) {
            baj=1;
        }
        k+=pl;
    }
    mini[n+1]=fel[n+1]=k;
    for (int i=n; i>=1; i--) {
        mini[i]=min(mini[i+1], fel[i+1]);
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        ut[b]=max(ut[b], a);
    }
    if (baj) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        sz.push_back({ert[i], ut[i]});
    }
    sort(sz.rbegin(), sz.rend());
    for (auto p:sz) {
        int pl=p.first, pos=p.second;
        if (mini[pos]>0) {
            ans+=pl;
            for (int i=pos+1; i<=n+1; i++) {
                fel[i]--;
            }
            for (int i=n; i>=1; i--) {
                mini[i]=min(fel[i+1], mini[i+1]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}