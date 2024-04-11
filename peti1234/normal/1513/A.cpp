#include <bits/stdc++.h>

using namespace std;
int w, n, k, t[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        if (2*k>=n) {
            cout << -1 << "\n";
        } else {
            for (int i=1; i<=n; i++) {
                t[i]=i;
            }
            for (int i=2; i<=2*k; i+=2) {
                swap(t[i], t[i+1]);
            }
            for (int i=1; i<=n; i++) {
                cout << t[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}