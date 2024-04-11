#include <bits/stdc++.h>

using namespace std;
const int c=200005, gy=250;
int n, m, pref[c], ert[gy][gy], x[c], y[c], z[c], kezd[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        z[i]=x[i]+y[i];
    }
    for (int i=1; i<=m; i++) {
        pref[i]+=pref[i-1];
        int op, id;
        cin >> op >> id;
        int s=(op==1 ? 1 : -1);
        if (op==1) {
            kezd[id]=i;
        }
        if (z[id]>=gy) {
            if (op==1) {
                int pos=kezd[id];
                while (pos<=m) {
                    pos+=x[id];
                    if (pos<=m) pref[pos]+=s;
                    pos+=y[id];
                    if (pos<=m) pref[pos]-=s;
                }
            } else {
                int pos=kezd[id];
                while (pos+z[id]<=i) {
                    pos+=z[id];
                }
                if (pos+x[id]<i) {
                    pref[i]--;
                }
                while (pos<=m) {
                    pos+=x[id];
                    if (pos<=m) pref[pos]+=s;
                    pos+=y[id];
                    if (pos<=m) pref[pos]-=s;
                }
            }
        } else {
            for (int j=kezd[id]+x[id]; j<kezd[id]+z[id]; j++) {
                ert[z[id]][j%z[id]]+=s;
            }
        }
        int sum=pref[i];
        for (int j=1; j<gy; j++) {
            sum+=ert[j][i%j];
        }
        cout << sum << "\n";
    }
    return 0;
}