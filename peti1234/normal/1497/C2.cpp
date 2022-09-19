#include <bits/stdc++.h>

using namespace std;
int w, n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=k-3; i++) {
            cout << 1 << " ";
            n--;
        }
        if (n%2) {
            cout << 1 << " " << n/2 << " " << n/2 << "\n";
        } else if (n%4==2) {
            cout << 2 << " " << n/2-1 << " " << n/2-1 << "\n";
        } else {
            cout << n/4 << " " << n/4 << " " << n/2 << "\n";
        }
    }
    return 0;
}