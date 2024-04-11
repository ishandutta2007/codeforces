#include <bits/stdc++.h>

using namespace std;
const int c=300004;
int n, m, sum, t[c][2], f[c], si[c], ell[c];
bool v[c], all[c];
int hv(int a) {
    if (!a) return 0;
    if (!f[a]) return a;
    int x=hv(f[a]); f[a]=x; return x;
}
void kv(int a) {if (a!=m+1) sum-=all[a]*si[a], all[a]=0;}
int unio(int a, int b) {
    if (a==b) return a;
    if (a>b) swap(a, b);
    si[b]+=si[a], si[a]=0, f[a]=b; return b;
}
int fix(int a, int b) {
    kv(a), kv(b), unio(a, m+1), unio(b, m+2);
}
void val(int a, int c) {
    if (a>c) swap(a, c);
    if (c<=m) {
        if (si[a]<si[c]) sum+=si[a], all[a]=1;
        else sum+=si[c], all[c]=1;
    }
}
void kapcs(int a, int b, int c, int d) {kv(a), kv(b), kv(c), kv(d), a=unio(a, b), c=unio(c, d), val(a, c), ell[a]=c, ell[c]=a;}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, ell[m+1]=m+2, ell[m+2]=m+1, all[m+1]=1;
    for (int i=1; i<=m; i++) si[i]=1;
    for (int i=1; i<=n; i++) {
        char c; cin >> c;
        if (c=='1') v[i]=1;
    }
    for (int i=1; i<=m; i++) {
        int x; cin >> x;
        for (int j=1; j<=x; j++) {
            int a; cin >> a;
            if (!t[a][0]) t[a][0]=i;
            else t[a][1]=i;
        }
    }
    for (int i=1; i<=n; i++) {
        int a=hv(t[i][0]), b=hv(t[i][1]), c=hv(ell[a]), d=hv(ell[b]);
        if (a) {
            if (!b) {
                if (v[i]) fix(c, a);
                else fix(a, c);
            } else {
                if (v[i]) kapcs(a, b, c, d);
                else kapcs(a, d, b, c);
            }
        }
        cout << sum+si[m+1] << "\n";
    }
    return 0;
}