#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, l, r, k;
    cin >> w;
    while (w--) {
        cin >> l >> r >> k;
        if (r==1) {
            cout << "NO\n";
            continue;
        }
        if (l==r) {
            cout << "YES\n";
            continue;
        }
        int db=(r+1)/2-l/2;
        cout << (k>=db ? "YES" : "NO") << "\n";
    }
    return 0;
}