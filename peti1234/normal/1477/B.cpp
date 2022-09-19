#include <bits/stdc++.h>

using namespace std;
const int c=(1<<20);
int w, n, q, po, kezd[c], veg[c], sum[c];
bool baj;
string x, y;
vector<pair<int, int> > sz;
int ask(int a, int fi, int se) {
    if (fi>veg[a] || se<kezd[a]) {
        return 0;
    }
    if (fi<=kezd[a] && veg[a]<=se) {
        return sum[a];
    }
    int tav=veg[a]-kezd[a]+1, x=2*a, y=2*a+1;
    if (sum[a]==0 || sum[a]==tav) {
        sum[x]=sum[y]=sum[a]/2;
    }
    return ask(x, fi, se)+ask(y, fi, se);
}
void add(int a, int fi, int se, int ert) {
    if (fi>veg[a] || se<kezd[a]) {
        return;
    }
    int tav=veg[a]-kezd[a]+1, x=2*a, y=2*a+1;
    if (fi<=kezd[a] && veg[a]<=se) {
        sum[a]=tav*ert;
        return;
    }
    if (sum[a]==0 || sum[a]==tav) {
        sum[x]=sum[y]=sum[a]/2;
    }
    add(x, fi, se, ert), add(y, fi, se, ert);
    sum[a]=sum[x]+sum[y];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> q >> x >> y;
        sz.clear(), baj=0, po=1;
        while (po<n) {
            po*=2;
        }
        for (int i=po; i<2*po; i++) {
            kezd[i]=veg[i]=i-po;
            sum[i]=(i<po+n && (y[i-po]=='1'));
        }
        for (int i=po-1; i>=1; i--) {
            kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
            sum[i]=sum[2*i]+sum[2*i+1];
        }
        for (int i=1; i<=q; i++) {
            int a, b; cin >> a >> b;
            sz.push_back({a-1, b-1});
        }
        for (int i=q-1; i>=0; i--) {
            int fi=sz[i].first, se=sz[i].second, tav=se-fi+1, ert=ask(1, fi, se);
            if (2*ert==tav) {
                baj=1;
            }
            add(1, fi, se, 2*ert>tav);
        }
        for (int i=0; i<n; i++) {
            if (ask(1, i, i)!=(x[i]=='1')) {
                baj=1;
            }
        }
        cout << (baj? "NO" : "YES") << "\n";
    }
    return 0;
}
/*
1
2 1
00
01
1 2
*/