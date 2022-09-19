#include <bits/stdc++.h>

using namespace std;
int w, n, x, gy;
bool jo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        jo=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            gy=sqrt(x);
            if (gy*gy!=x) {
                jo=1;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}