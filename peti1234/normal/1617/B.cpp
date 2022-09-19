#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int x;
        cin >> x;
        for (int i=2; ; i++) {
            if (__gcd(i, x-i-1)==1) {
                cout << i << " " << x-i-1 << " " << 1 << "\n";
                break;
            }
        }
    }
    return 0;
}