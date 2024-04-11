#include <bits/stdc++.h>

using namespace std;
const int c=1000005, k=21;
int n, szint[c], fel[c][k], bal, jobb, dist;
int lca(int a, int b) {
    if (szint[a]<szint[b]) swap(a, b);
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) a=fel[a][i];
    }
    for (int i=k-1;i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a==b) return a;
    return fel[a][0];
}
int tav(int a, int b) {
    return szint[a]+szint[b]-2*szint[lca(a, b)];
}
void add(int a, int x) {
    szint[a]=szint[x]+1;
    fel[a][0]=x;
    for (int i=1; i<k; i++) fel[a][i]=fel[fel[a][i-1]][i-1];
    int p=tav(a, bal), q=tav(a, jobb);
    if (max(p, q)>dist) {
        if (p>=q) {
            jobb=a;
            dist=p;
        } else {
            bal=a;
            dist=q;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    bal=1, jobb=1;

    add(2, 1);
    add(3, 1);
    add(4, 1);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        add(2*i+3, x);
        add(2*i+4, x);
        cout << dist << "\n";
    }
    return 0;
}