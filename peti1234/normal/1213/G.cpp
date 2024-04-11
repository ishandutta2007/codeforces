#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int ki[c], n, q;
long long sum, si[c], sol[c];
vector<pair<int, pair<int, int> > > sz;
int holvan(int a) {
    if (!ki[a]) return a;
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
int unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[b]=a;
        sum+=si[a]*si[b];
        si[a]+=si[b], si[b]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) si[i]=1;
    for (int i=1; i<n; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz.push_back({c, {a, b}});
    }
    for (int i=1; i<=q; i++) {
        int x; cin >> x;
        sz.push_back({x, {c, i}});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<sz.size(); i++) {
        int a=sz[i].second.first, b=sz[i].second.second;
        if (a<c) unio(a, b);
        else sol[b]=sum;
    }
    for (int i=1; i<=q; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}