#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        bool baj=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (i>30) {
                continue;
            }
            bool s=0;
            for (int j=1; j<=i+1; j++) {
                if (x%j) {
                    s=1;
                }
            }
            if (!s) {
                baj=1;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}