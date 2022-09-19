#include <bits/stdc++.h>

using namespace std;
int w, n, t[102], kis, nagy;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        kis=1, nagy=1;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]<t[kis]) {
                kis=i;
            }
            if (t[i]>t[nagy]) {
                nagy=i;
            }
        }
        if (kis>nagy) {
            swap(kis, nagy);
        }
        cout << min({nagy, n-kis+1, n-nagy+kis+1}) << "\n";
    }
    return 0;
}