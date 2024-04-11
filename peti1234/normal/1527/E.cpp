#include <bits/stdc++.h>

using namespace std;
const int c=35002, sok=1e9;
int t[c], ut[c], el[c], kov[c], n, k;
int regi[c], uj[c];
void solve(int lo, int hi, int bal, int jobb, int prec) {
    if (lo>hi) {
        return;
    }
    jobb=min(jobb, hi-1);
    int mid=(lo+hi)/2, ik=bal+1, iv=lo-1, ert=prec;
    while (iv<mid) {
        iv++;
        if (el[iv]>=ik) {
            ert+=iv-el[iv];
        }
    }
    int pos=bal;
    uj[mid]=regi[bal]+ert;
    for (int i=bal+1; i<=min(mid-1, jobb); i++) {
        if (kov[ik]<=iv) {
            ert-=kov[ik]-ik;
        }
        ik++;
        if (regi[i]+ert<uj[mid]) {
            pos=i;
            uj[mid]=regi[i]+ert;
        }
    }
    while (pos+1<ik) {
        ik--;
        if (kov[ik]<=iv) {
            ert+=kov[ik]-ik;
        }
    }
    solve(lo, mid-1, bal, pos, prec), solve(mid+1, hi, pos, jobb, ert);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (ut[t[i]]) {
            el[i]=ut[t[i]];
            kov[ut[t[i]]]=i;
        }
        ut[t[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        if (!el[i]) {
            el[i]=i;
        }
        if (!kov[i]) {
            kov[i]=i;
        }
    }
    for (int i=1; i<=n; i++) {
        regi[i]=sok;
        uj[i]=sok;
    }
    for (int i=1; i<=k; i++) {
        solve(1, n, 0, n-1, 0);
        for (int j=1; j<=n; j++) {
            regi[j]=uj[j];
            uj[j]=sok;
        }
    }
    cout << regi[n] << "\n";
    return 0;
}