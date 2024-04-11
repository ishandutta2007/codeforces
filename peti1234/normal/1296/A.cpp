#include <bits/stdc++.h>

using namespace std;
int w, n, x, a, b;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n, a=0, b=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (x%2) {
                a++;
            } else {
                b++;
            }
        }
        cout << ((a && (b || n%2)) ? "YES" : "NO") << "\n";
    }
}