#include <bits/stdc++.h>

using namespace std;
int w, n, t[1005], db;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        while (!is_sorted(t+1, t+n+1)) {
            db++;
            for (int i=1; i<n; i+=2) {
                int s=i+1-db%2;
                if (t[s]>t[s+1]) {
                    swap(t[s], t[s+1]);
                }
            }
        }
        cout << db << "\n";
        db=0;
    }
    return 0;
}