#include <bits/stdc++.h>

using namespace std;
int w, n, db[51];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=2*n; i++) {
            int x; cin >> x, db[x]++;
            if (db[x]%2) cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}