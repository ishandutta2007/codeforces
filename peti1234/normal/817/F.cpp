#include <bits/stdc++.h>

using namespace std;
const int c=1<<20;
int q, kezd[c], veg[c], ert[c]; // ert=1 ha csak 0, ert=2, ha csak 1, ert=3, ha forditva van az egesz
long long ll[c], rr[c], tp[c], cnt, po=1, sok=1e18;
vector<long long> sz;
map<long long, int> m;
int metsz(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) return 0;
    if (l<=kezd[a] && veg[a]<=r) return 2;
    return 1;
}
void push(int a) {
    int x=2*a, y=2*a+1, s=ert[a];
    if (s==1 || s==2) {
        ert[x]=s, ert[y]=s;
    }
    if (s==3) {
        ert[x]=3-ert[x], ert[y]=3-ert[y];
    }
    ert[a]=0;
}
void calc(int a) {
    int x=2*a, y=2*a+1;
    assert(ert[a]==0);
    if (ert[x]==1 && ert[y]==1) ert[a]=1;
    if (ert[x]==2 && ert[y]==2) ert[a]=2;
}
void add(int a, int l, int r, int id) {
    if (a==1) {
        //cout << "add " << l << " " << r << " " << id << "\n";
    }
    int s=metsz(a, l, r);
    if (s==0) return;
    if (s==2) {
        if (id==1 || id==2) ert[a]=id;
        else ert[a]=3-ert[a];
        return;
    }
    push(a);
    add(2*a, l, r, id), add(2*a+1, l, r, id);
    calc(a);
}
int ask(int a) {
    if (kezd[a]==veg[a]) return kezd[a];
    push(a);
    calc(a);
    int x=2*a, y=2*a+1;
    if (ert[x]!=2) return ask(x);
    else return ask(y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> tp[i] >> ll[i] >> rr[i];
        sz.push_back(ll[i]-1), sz.push_back(rr[i]);
    }
    sz.push_back(0);
    sz.push_back(sok+1);
    sort(sz.begin(), sz.end());
    sz.erase(unique(sz.begin(), sz.end()), sz.end());
    for (auto x:sz) {
        //cout << "ertek " << x << "\n";
        m[x]=++cnt;
    }
    while (po<=cnt) {
        po*=2;
    }
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po+1, veg[i]=i-po+1;
        ert[i]=1;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
        ert[i]=1;
    }

    add(1, 1, 1, 2);
    for (int i=1; i<=q; i++) {
        int l=m[ll[i]-1]+1, r=m[rr[i]], t=tp[i];
        if (t==1 || t==2) t=3-t;
        add(1, l, r, t);
        int pos=ask(1);
        cout << sz[pos-2]+1 << "\n";
    }
    return 0;
}
/*
3
1 1 1000000000000000000
3 1231 132412133
3 1231 23423424242342
*/