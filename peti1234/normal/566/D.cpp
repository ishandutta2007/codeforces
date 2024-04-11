#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, q, kov[c], ki[c];
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        kov[i]=i+1;
    }
    for (int i=1; i<=q; i++) {
        int q, a, b;
        cin >> q >> a >> b;
        if (q==1) {
            unio(a, b);
        }
        if (q==2) {
            while(a<b) {
                unio(a, b);
                int aa=a;
                a=kov[a];
                kov[aa]=b+1;
            }
        }
        if (q==3) {
            cout << (holvan(a)==holvan(b) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}