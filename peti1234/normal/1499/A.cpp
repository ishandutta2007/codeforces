#include <bits/stdc++.h>

using namespace std;
int q, n, k1, k2, w, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        cin >> n >> k1 >> k2 >> w >> b;
        cout << (2*w<=k1+k2 && 2*b<=2*n-k1-k2 ? "YES" : "NO") << "\n";
    }
    return 0;
}