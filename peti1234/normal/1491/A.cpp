#include <bits/stdc++.h>

using namespace std;
int n, q, t[100002], a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]) {
            b++;
        } else {
            a++;
        }
    }
    for (int i=1; i<=q; i++) {
        int x, y;
        cin >> x >> y;
        if (x==1) {
            if (t[y]) {
                b--, a++;
            } else {
                b++, a--;
            }
            t[y]=1-t[y];
        } else {
            if (b>=y) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}