#include <bits/stdc++.h>

using namespace std;
const int c=1<<20;
int n, q, kezd[c], veg[c], cl[c];
long long ert[c], fix[c], po[61];
int be[c], ki[c], cnt;
vector<int> sz[c];
bool v[c];

void init(int a) {
    int po=1;
    while (po<=a) po*=2;
    for (int i=po; i<2*po; i++) kezd[i]=veg[i]=i-po+1;
    for (int i=po-1; i>=1; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
}
int s(int pos, int l, int r) {
    if (kezd[pos]>r || veg[pos]<l) return 0;
    if (l<=kezd[pos] && veg[pos]<=r) return 2;
    return 1;
}
void add(int a, int l, int r, long long val) {
    if (a==1) {
        //cout << "add " << l << " " << r << " " << val << "\n";
    }
    int p=s(a, l, r);
    if (!p) return;
    if (p==2) {
        ert[a]=val;
        fix[a]=val;
        return;
    }
    int x=2*a, y=2*a+1;
    if (fix[a]) {
        ert[x]=fix[x]=fix[a], ert[y]=fix[y]=fix[a];
        fix[a]=0;
    }
    add(x, l, r, val), add(y, l, r, val);
    ert[a]=ert[x]|ert[y];
}
long long ask(int a, int l, int r) {
    if (a==1) {
        //cout << "ask " << a << " " << l << " " << r << "\n";
    }
    int p=s(a, l, r);
    if (!p) return 0;
    if (p==2 || fix[a]) return ert[a];
    return ask(2*a, l, r)|ask(2*a+1, l, r);
}
void dfs(int a) {
    //cout << "dfs " << a << "\n";
    be[a]=++cnt;
    add(1, be[a], n, po[cl[a]]);
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    ki[a]=cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    po[1]=1;
    for (int i=2; i<=60; i++) po[i]=po[i-1]*2,
    init(n);
    for (int i=1; i<=n; i++) cin >> cl[i];
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    for (int i=1; i<=q; i++) {
        int id;
        cin >> id;
        if (id==1) {
            int pos, ert;
            cin >> pos >> ert;
            add(1, be[pos], ki[pos], po[ert]);
        } else {
            int pos;
            cin >> pos;
            long long res=ask(1, be[pos], ki[pos]);
            //cout << "valasz...................................... ";
            cout << __builtin_popcountll(res) << "\n";
        }
    }
    return 0;
}
/*
2 1
1 2
1 2
2 1
*/