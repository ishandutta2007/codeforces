#include <bits/stdc++.h>

using namespace std;
const int c=35005;
int n, k, t[c], cnt[c], L=1, R, DB, regi[c], uj[c];
int calc(int a, int b) {
    while (L>a) {
        L--;
        cnt[t[L]]++;
        if (cnt[t[L]]==1) {
            DB++;
        }
    }
    while (R<b) {
        R++;
        cnt[t[R]]++;
        if (cnt[t[R]]==1) {
            DB++;
        }
    }
    while (L<a) {
        cnt[t[L]]--;
        if (cnt[t[L]]==0) {
            DB--;
        }
        L++;
    }
    while (R>b) {
        cnt[t[R]]--;
        if (cnt[t[R]]==0) {
            DB--;
        }
        R--;
    }
    return DB;
}
void solve(int kezd, int veg, int l, int r) {
    if (kezd>veg) {
        return;
    }
    int koz=(kezd+veg)/2;
    int pos=0, ert=0;
    for (int i=l; i<=min(koz, r); i++) {
        if (regi[i-1]+calc(i, koz)>ert) {
            ert=regi[i-1]+DB, pos=i;
        }
    }
    uj[koz]=ert;
    solve(kezd, koz-1, l, pos);
    solve(koz+1, veg, pos, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=k; i++) {
        solve(1, n, 1, n);
        for (int j=1; j<=n; j++) {
            regi[j]=uj[j];
            uj[j]=0;
        }
    }
    cout << regi[n] << "\n";
    return 0;
}