#include <bits/stdc++.h>

using namespace std;
const int c=(1<<19);
int n, ans[c];
vector<int> sz[c];
int kezd[c], veg[c], lp[c], mini[c], maxi[c];
void init(int a) {
    int po=1;
    while (po<a) {
        po*=2;
    }
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po, veg[i]=i-po;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
}
void add(int a, int l, int r, int ert) {
    if (kezd[a]>r || veg[a]<l) {
        return;
    }
    if (l<=kezd[a] && veg[a]<=r) {
        lp[a]+=ert;
        maxi[a]+=ert, mini[a]+=ert;
        return;
    }
    int x=2*a, y=2*a+1;
    add(x, l, r, ert), add(y, l, r, ert);
    maxi[a]=lp[a]+max(maxi[x], maxi[y]);
    mini[a]=lp[a]+min(mini[x], mini[y]);
}
int ask(int a, int l, int r, bool t) {
    if (kezd[a]>r || veg[a]<l) {
        return (t ? -c : c);
    }
    if (l<=kezd[a] && veg[a]<=r) {
        return (t ? maxi[a] : mini[a]);
    }
    int x=ask(2*a, l, r, t), y=ask(2*a+1, l, r, t);
    return lp[a]+(t ? max(x, y) : min(x, y));
}
void calc(int a, bool t) {
    int dif=ask(1, a, n, !t)-ask(1, 0, a-1, t), ert=0;
    if (t==0) {
        ert=dif/2;
    } else {
        ert=(-dif-1)/2;
    }
    ans[a]=max(ans[a], ert);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    init(n+1);

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz[x].push_back(i);
    }

    for (int i=1; i<=n; i++) {
        add(1, i, n, 1);
    }
    for (int i=1; i<=n; i++) {
        for (auto x:sz[i]) {
            calc(x, 0);
        }
        for (auto x:sz[i]) {
            add(1, x, n, -2);
        }
        for (auto x:sz[i]) {
            calc(x, 1);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}