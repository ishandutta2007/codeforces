#include <bits/stdc++.h>

using namespace std;
const int c=(1<<18), k=2*c;
int n, po=1, kezd[k], veg[k], t[c], inv[c], ert[c];
long long sok=1e15, mini[k], lp[k], ans;
void init(int po) {
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po+1, veg[i]=i-po+1;
    }
    for (int i=po-1; i>=0; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
}
void add(int a, int l, int r, int pl) {
    if (a==1) {
        //cout << "add " << l << " " << r << " " << pl << "\n";
    }
    int bal=kezd[a], jobb=veg[a];
    if (bal>r || jobb<l) {
        return;
    }
    if (l<=bal && jobb<=r) {
        lp[a]+=pl;
        return;
    }
    int x=2*a, y=2*a+1;
    add(x, l, r, pl), add(y, l, r, pl);
    mini[a]=min(mini[x]+lp[x], mini[y]+lp[y]);
}
long long ask(int a, int l, int r) {
    int bal=kezd[a], jobb=veg[a];

    if (bal>r || jobb<l) {
        return sok;
    }
    if (l<=bal && jobb<=r) {
        return mini[a]+lp[a];
    }
    int x=2*a, y=2*a+1;
    long long ert=min(ask(x, l, r), ask(y, l, r));
    return ert+lp[a];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (po<n) {
        po*=2;
    }
    init(po);
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        inv[t[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
    }
    ans=min(ert[1], ert[n]);
    for (int i=1; i<=n; i++) {
        add(1, i, n, ert[i]);
    }
    for (int i=1; i<=n; i++) {
        int pos=inv[i];
        add(1, pos, n, -ert[pos]);
        add(1, 1, pos-1, ert[pos]);
        ans=min(ans, ask(1, 1, n-1));
    }
    cout << ans << "\n";
    return 0;
}