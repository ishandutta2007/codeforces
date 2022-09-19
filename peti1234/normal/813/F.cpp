#include <bits/stdc++.h>

using namespace std;
const int c=1<<18;
int kezd[c], veg[c], n, q, po=1;
int si[c], fel[c], also[c], eldb, baj;
vector<pair<int, int> > sz[c];
map<pair<int, int>, int> m;
void add(int a, int l, int r, pair<int, int> p) {
    if (kezd[a]>r || veg[a]<l) return;
    if (l<=kezd[a] && veg[a]<=r) {
        sz[a].push_back(p);
    } else {
        add(2*a, l, r, p);
        add(2*a+1, l, r, p);
    }
}
int holvan(int a) {
    return (fel[a] ? holvan(fel[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        if (si[a]<si[b]) {
            swap(a, b);
        }
        also[++eldb]=b;
        fel[b]=a;
        si[a]+=si[b];
    }
}
void dfs(int a) {
    int alap=eldb, baj2=baj;
    for (auto p:sz[a]) {
        int x=p.first, y=p.second;
        unio(x, y+n);
        unio(x+n, y);
        if (holvan(x)==holvan(x+n)) {
            baj=1;
        }
    }
    if (a>=po) {
        if (1<=kezd[a] && kezd[a]<=q) {
            cout << (baj ? "NO" : "YES") << "\n";
        }
    } else {
        dfs(2*a);
        dfs(2*a+1);
    }
    while (eldb>alap) {
        int x=also[eldb], y=fel[x];
        eldb--;
        fel[x]=0;
        si[y]-=si[x];
    }
    baj=baj2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    while (po<=q) {
        po*=2;
    }
    for (int i=po; i<=2*po; i++) {
        kezd[i]=i-po, veg[i]=i-po;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> p={a, b};
        int x=m[p];
        if (x) {
            m.erase(p);
            add(1, x, i-1, p);
        } else {
            m[p]=i;
        }
    }
    for (auto x:m) {
        assert(x.second>0);
        add(1, x.second, q, x.first);
    }
    for (int i=1; i<=n; i++) si[i]=1;
    dfs(1);
    return 0;
}