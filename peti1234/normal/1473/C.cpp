#include <bits/stdc++.h>

using namespace std;
int w, n, k, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        db=2*k-1-n;
        for (int i=1; i<=db; i++) {
            cout << i << " ";
        }
        for (int i=k; i>db; i--) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}