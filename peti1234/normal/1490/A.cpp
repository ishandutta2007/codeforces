#include <bits/stdc++.h>

using namespace std;
int w, n, db, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a;
        db=0;
        for (int i=1; i<n; i++) {
            cin >> b;
            int s=2;
            while (min(a, b)*s<max(a, b)) {
                db++, s*=2;
            }
            a=b;
        }
        cout << db << "\n";
    }
    return 0;
}