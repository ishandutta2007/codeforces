#include <bits/stdc++.h>

using namespace std;
const int c=(1<<21), f=c/2;
int n, m, q, kezd[c], veg[c], ert[c], maxi[c], a[c], b[c];
void add(int a, int l, int r, int b) {
    if (kezd[a]>r || veg[a]<l) return;
    if (l<=kezd[a] && veg[a]<=r) {
        ert[a]+=b;
        maxi[a]+=b;
        return;
    }
    int x=2*a, y=2*a+1;
    add(x, l, r, b), add(y, l, r, b);
    maxi[a]=ert[a]+max(maxi[x], maxi[y]);
}
int ask(int a, int b) {
    if (maxi[a]<=b) return -1;
    if (kezd[a]==veg[a]) return kezd[a];
    int x=2*a, y=2*a+1, s=b-ert[a];
    return ask((maxi[y]>s ? y : x), s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=f; i<c; i++) kezd[i]=veg[i]=i-f+1;
    for (int i=f-1; i>=1; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        add(1, 1, a[i], 1);
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
        add(1, 1, b[i], -1);
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int id, pos, ert;
        cin >> id >> pos >> ert;
        if (id==1) {
            add(1, 1, a[pos], -1);
            a[pos]=ert;
            add(1, 1, a[pos], 1);
        } else {
            add(1, 1, b[pos], 1);
            b[pos]=ert;
            add(1, 1, b[pos], -1);
        }
        cout << ask(1, 0) << "\n";
    }
    return 0;
}