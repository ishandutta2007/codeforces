#include <bits/stdc++.h>

using namespace std;
int n, x, db, k=2000;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if ((x+k)%2) {
            if (db%2) x++;
            else x--;
            db++;
        }
        cout << x/2 << "\n";
    }
    return 0;
}