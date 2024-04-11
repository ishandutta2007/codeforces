#include <bits/stdc++.h>

using namespace std;
int w, n, x;
void ans(int a, int b) {
    cout << a << " " << b << " " << b+1 << "\n";
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> x;
        }
        cout << 3*n << "\n";
        for (int i=1; i<=n; i+=2) {
            for (int j=1; j<=2; j++) {
                ans(2, i), ans(1, i), ans(2, i);
            }
        }
    }
    return 0;
}