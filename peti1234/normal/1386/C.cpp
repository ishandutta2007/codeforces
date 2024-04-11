#include<bits/stdc++.h>
using namespace std;

const int c=500002;

int ki[c], eldb, si[c], r[c];
int holvan(int a) {
    if (ki[a]) return holvan(ki[a]);
    return a;
}
int unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        eldb++;
        if (si[a]<si[b]) {
            ki[a]=b, si[b]+=si[a];
            r[eldb]=a;
        } else {
            ki[b]=a, si[a]+=si[b];
            r[eldb]=b;
        }
    }
}
int torol(int ert) {
    while(eldb>ert) {
        int v=r[eldb];
        si[ki[v]]-=si[v], ki[v]=0;
        eldb--;
    }
}
int n, m, q, ans[c], kezd[c], veg[c];
bool add(int id) {
    int bcs=kezd[id], jcs=veg[id];
    unio(bcs+n, jcs), unio(bcs, jcs+n);
    return (holvan(bcs)==holvan(bcs+n));
}

void solve(int bal, int jobb, int kis, int nagy) {
    if (bal>jobb) {
        return;
    }
    if (kis==nagy) {
        for (int i=bal; i<=jobb; i++) {
            ans[i]=kis;
        }
        return;
    }
    int elkezd=eldb;
    int koz=(bal+jobb)/2;
    bool pkor=0;
    for (int i=min(bal, kis); i<koz; i++) {
        if (add(i)) {
            pkor=1;
        }
    }
    if (pkor) {
        ans[koz]=nagy;
    }
    int elkozep=eldb;
    for (int i=nagy-1; i>=koz && !pkor; i--) {
        if (add(i)) {
            pkor=1;
            ans[koz]=i;
        }
    }
    int ert=ans[koz];
    if (!ert) {
        return;
    }
    torol(elkozep);
    if (add(koz)) {
        for (int i=koz+1; i<=jobb; i++) {
            ans[i]=nagy;
        }
    } else {
        solve(koz+1, jobb, ert, nagy);
    }
    torol(elkezd);
    bool spec=0;
    for (int i=ert; i<nagy; i++) {
        if (add(i)) {
            spec=1;
        }
    }
    if (spec) {
        for (int i=bal; i<koz; i++) {
            ans[i]=ert;
        }
    } else {
        solve(bal, koz-1, kis, ert);
    }
    torol(elkezd);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=1; i<=2*n; i++) {
        si[i]=1;
    }
    for (int i=1; i<=m; i++) {
        cin >> kezd[i] >> veg[i];
    }
    solve(1, m, 1, m+1);

    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        cout <<(ans[a]>b ? "YES" : "NO") << "\n";
    }
	return 0;
}