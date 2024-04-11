#include <bits/stdc++.h>

using namespace std;
long long w, n, x, t, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> x >> t;
        s=t/x;
        if (n<=s) {
            cout << n*(n-1)/2 << "\n";
        } else {
            cout << s*(n-s)+s*(s-1)/2 << "\n";
        }

    }
    return 0;
}