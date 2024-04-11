#include <bits/stdc++.h>

using namespace std;
int w, n, k, xo;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> k;
        xo=0;
        for (int i=0; i<n; i++) {
            cout.flush() << (xo^i) << "\n";
            int x;
            cin >> x;
            if (x==1) {
                break;
            }
            xo=i;
        }
    }
    return 0;
}