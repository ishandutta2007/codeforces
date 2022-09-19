#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=30;
int n, m, si[c][k], ki[c][k], q;
int holvan(int a, int id) {
    return (ki[a][id] ? ki[a][id]=holvan(ki[a][id], id) : a
            );
}
void unio(int a, int b, int id) {
    a=holvan(a, id), b=holvan(b, id);
    if (a!=b) {
        si[a][id]+=si[b][id];
        ki[b][id]=a;
    }
}
void add(int a) {
    for (int i=0; i<k; i++) {
        si[holvan(a, i)][i]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c%2==0) {
            add(a);
            add(b);
        }
        for (int id=0; id<30; id++) {
            if (c & (1<<id)) {
                unio(a, b, id);
            }
        }
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        int o=0, e=0;
        for (int id=0; id<30; id++) {
            int aa=holvan(a, id), bb=holvan(b, id);
            if (aa==bb) {
                o=1;
            }
            if (id && si[aa][id]) {
                e=1;
            }
        }
        if (o) cout << 0 << "\n";
        else if (e) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    return 0;
}