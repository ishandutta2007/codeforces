#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, ert=1;
        cin >> n;
        while (ert<n) ert*=2;
        ert--;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if (x!=i) {
                ert&=x;
            }
        }
        cout << ert << "\n";
    }
    return 0;
}