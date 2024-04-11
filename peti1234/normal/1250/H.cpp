#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, db[c], t[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (i%2) {
                db[t[i]]++;
            }
        }
        sort(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            if (i%2) {
                db[t[i]]--;
            }
        }
        bool jo=1;
        for (int i=0; i<c; i++) {
            if (db[i]) {
                jo=0;
            }
            db[i]=0;
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}