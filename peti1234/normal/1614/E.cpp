#include <bits/stdc++.h>

using namespace std;
const int c=10000005, mod=1e9+1;
int n, kezd[c], veg[c], bal[c], jobb[c], mini[c], maxi[c], valt[c], cnt=1, q, ut;
void add(int pos, int ert) {
    if (mini[pos]>ert) {
        valt[pos]--, mini[pos]--, maxi[pos]--;
        return;
    }
    if (maxi[pos]<ert) {
        valt[pos]++, mini[pos]++, maxi[pos]++;
        return;
    }
    if (mini[pos]==ert && maxi[pos]==ert) {
        return;
    }
    if (!bal[pos]) {
        int mid=(kezd[pos]+veg[pos])/2;
        bal[pos]=++cnt;
        kezd[cnt]=kezd[pos], veg[cnt]=mid, mini[cnt]=kezd[cnt], maxi[cnt]=veg[cnt];
        jobb[pos]=++cnt;
        kezd[cnt]=mid+1, veg[cnt]=veg[pos], mini[cnt]=kezd[cnt], maxi[cnt]=veg[cnt];
    }
    int a=bal[pos], b=jobb[pos];
    if (valt[pos]) {
        valt[a]+=valt[pos], mini[a]+=valt[pos], maxi[a]+=valt[pos];
        valt[b]+=valt[pos], mini[b]+=valt[pos], maxi[b]+=valt[pos];
        valt[pos]=0;
    }
    add(a, ert), add(b, ert);
    mini[pos]=mini[a], maxi[pos]=maxi[b];
}
int ask(int pos, int ert) {
    if (kezd[pos]>ert || veg[pos]<ert) return 0;
    if (!bal[pos]) {
        return ert+valt[pos];
    }
    return valt[pos]+max(ask(bal[pos], ert), ask(jobb[pos], ert));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    veg[1]=1e9, maxi[1]=1e9;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, q;
        cin >> x >> q;
        add(1, x);
        while (q--) {
            cin >> x;
            x=(x+ut)%mod;
            ut=ask(1, x);
            cout << ut << "\n";
        }
    }
    return 0;
}