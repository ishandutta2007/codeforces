#include <bits/stdc++.h>

using namespace std;
int n, w=524288, akt;
int el[1050001], ve[1050001], ert[1050001], lp[1050001], pos[300001];
int ask(int id, int st, int fi) {
    int x=el[id], y=ve[id], a=2*id, b=2*id+1;
    if (st>y || fi<x) return 0;
    if (st<=x && y<=fi) return ert[id]+lp[id];
    lp[a]+=lp[id], lp[b]+=lp[id], lp[id]=0;
    ert[id]=min(ask(a, st, fi), ask(b, st, fi));
    return ert[id];
}
void add(int id, int st, int fi, int s) {
    int x=el[id], y=ve[id], a=2*id, b=2*id+1;
    if (st>y || fi<x) return;
    if (st<=x && y<=fi) {
        lp[id]+=s;
        return;
    }
    add(a, st, fi, s), add(b, st, fi, s);
    ert[id]=min(ert[a]+lp[a], ert[b]+lp[b]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, akt=n+1;
    for (int i=w; i<2*w; i++) el[i]=i-w+1, ve[i]=i-w+1;
    for (int i=w-1; i>=1; i--) el[i]=el[2*i], ve[i]=ve[2*i+1];
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        pos[x]=i;
    }
    for (int i=1; i<=n; i++) {
        while(ask(1, 1, n)>=0) {
            akt--;
            add(1, 1, pos[akt], -1);
        }
        cout << akt << " ";
        int x;
        cin >> x;
        add(1, 1, x, 1);
    }
    return 0;
}