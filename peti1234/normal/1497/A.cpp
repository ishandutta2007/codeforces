#include <bits/stdc++.h>

using namespace std;
int w, n, db[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            db[x]++;
        }
        for (int i=0; i<=100; i++) {
            if (db[i]) {
                cout << i << " ";
                db[i]--;
            }
        }
        for (int i=0; i<=100; i++) {
            while (db[i]) {
                cout << i << " ";
                db[i]--;
            }
        }
        cout << "\n";
    }
    return 0;
}