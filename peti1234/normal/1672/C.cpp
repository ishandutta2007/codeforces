#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, kezd=0, veg=0, el=0, x;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (x==el) {
                if (!kezd) {
                    kezd=i-1;
                }
                veg=i-1;
            }
            el=x;
        }
        cout << (kezd==veg ? 0 : max(1, veg-kezd-1)) << "\n";
    }
    return 0;
}