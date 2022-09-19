#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=20;
int n, q, fel[c][k], t[c], ut[c], veg;
vector<int> oszt[c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<c; i++) {
        if (oszt[i].size()==0) {
            for (int j=i; j<c; j+=i) {
                oszt[j].push_back(i);
            }
        }
    }
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        int pos=0;
        for (int x:oszt[t[i]]) {
            pos=max(pos, ut[x]);
            ut[x]=i;
        }
        for (int j=veg+1; j<=pos; j++) {
            fel[j][0]=i;
        }
        veg=max(veg, pos);
    }
    for (int i=1; i<=n; i++) {
        if (!fel[i][0]) {
            fel[i][0]=n+1;
        }
    }
    fel[n+1][0]=n+1;
    for (int j=1; j<k; j++) {
        for (int i=1; i<=n+1; i++) {
            fel[i][j]=fel[fel[i][j-1]][j-1];
        }
    }
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        int ans=0;
        for (int j=k-1; j>=0; j--) {
            if (fel[l][j]<=r) {
                ans+=(1<<j);
                l=fel[l][j];
            }
        }
        cout << ans+1 << "\n";
    }
    return 0;
}