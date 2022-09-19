#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, m, ki[c], ert[c];
vector<pair<int, int> > sz;
bool baj;
int xo(int a) {
    return (ki[a]==0 ? 0 : ert[a]^xo(ki[a]));
}
int holvan(int a) {
    ert[a]=xo(a);
    return (ki[a]==0 ? a : ki[a]=holvan(ki[a]));
}
void unio(int a, int b, int c, int d) {
    int p=xo(a)^xo(b)^c;
    a=holvan(a), b=holvan(b);
    if (a==b) {
        if (d==1 && p || d==0 && __builtin_popcount(p)%2) {
            baj=true;
        }
    } else {
        ki[a]=b;
        ert[a]=p;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            sz.push_back({a, b});
            if (c!=-1) {
                unio(a, b, c, 1);
            }
        }
        for (int i=1; i<=m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            unio(a, b, c, 0);
        }
        for (int i=1; i<=n; i++) {
            if (holvan(i)!=holvan(1)) {
                unio(1, i, 0, 1);
            }
        }
        if (baj) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (auto x:sz) {
                cout << x.first << " " << x.second << " " << (xo(x.first)^xo(x.second)) << "\n";
            }
        }
        baj=0;
        sz.clear();
        for (int i=1; i<=n; i++) {
            ki[i]=0, ert[i]=0;
        }
    }
    return 0;
}