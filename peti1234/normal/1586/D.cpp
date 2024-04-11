#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, kov[c], kis, ans[c];
int kerd(int a, int b) {
    cout << "? ";
    for (int i=1; i<=n; i++) {
        if (i==a) {
            cout << (b ? 2 : 1) << " ";
        } else {
            cout << (b ? 1 : 2) << " ";
        }
    }
    cout.flush() << endl;
    int x;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a=kerd(i, 1), b=kerd(i, 0);
        if (!b) {
            kis=i;
        }
        if (a && a!=i) {
            kov[i]=a;
        }
        if (b && b!=i) {
            kov[b]=i;
        }
    }
    for (int i=1; i<=n; i++) {
        ans[kis]=i;
        kis=kov[kis];
    }
    cout << "! ";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}