#include<bits/stdc++.h>
using namespace std;
const int f=1048576, c=f/2;
int n, q, k, d=1, dd=1, el, x[c], y[c], ki[c], si[c], r[c], l[c], w[c], st[f], fi[f];
vector<int> sz[f];
int hv(int a) {
    if (ki[a]) return hv(ki[a]);
    return a;
}
int unio(int a, int b) {
    a=hv(a), b=hv(b);
    if (a!=b) {
        el++;
        if (si[a]<si[b]) {
            ki[a]=b, si[b]+=si[a];
            r[el]=a;
        } else {
            ki[b]=a, si[a]+=si[b];
            r[el]=b;
        }
    }
}
int visz(int ert) {
    while(el>ert) {
        int v=r[el];
        si[ki[v]]-=si[v], ki[v]=0;
        el--;
    }
}
void add(int a, int l, int r) {
    int p=st[a], q=fi[a];
    if (p>r || q<l) return;
    if (l<=p && q<=r) {
        sz[a].push_back(l);
    } else {
        add(2*a, l, r);
        add(2*a+1, l, r);
    }
}
void sol(int a) {
    int db=el;
    for (int i=0; i<sz[a].size(); i++) {
        unio(x[sz[a][i]], y[sz[a][i]]);
    }
    if (a<c) {
        sol(2*a);
        sol(2*a+1);
    } else {
        if (w[a-c+1]==2) {
            cout << si[hv(x[a-c+1])] << "\n";
        }
    }
    visz(db);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> k;
    for (int i=1; i<=n; i++) si[i]=1;
    for (int i=1; i<=q; i++) {
        cin >> w[i];
        if (w[i]==1) cin >> x[i] >> y[i];
        if (w[i]==2) cin >> x[i];
        if (w[i]==3) l[d]=i, d++;
    }
    l[d]=q;
    for (int i=c; i<f; i++) st[i]=i-c+1, fi[i]=i-c+1;
    for (int i=c-1; i>=1; i--) st[i]=st[2*i], fi[i]=fi[2*i+1];
    for (int i=1; i<=q; i++) {
        if (w[i]==1) {
            add(1, i, l[min(d, dd+k-1)]);
        }
        if (w[i]==3) {
            dd++;
        }
    }
    sol(1);
	return 0;
}