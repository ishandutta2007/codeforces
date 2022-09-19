#include <bits/stdc++.h>

using namespace std;
int x, y;
int p, m;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        if (k>0) {
            p++;
            x=k;
        }
        if (k<0) {
            m++;
            y=k;
        }
    }
    if (max(m, p)*2<n) {
        cout << 0 << endl;
    } else {
        if (p>m) {
            cout << x << endl;
        } else {
            cout << y << endl;
        }
    }
    return 0;
}