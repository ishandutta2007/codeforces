#include <bits/stdc++.h>

using namespace std;
int w, n, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, db=(n+3)/4;
        n-=db;
        for (int i=1; i<=n; i++) cout << 9;
        for (int i=1; i<=db; i++) cout << 8;
        cout << "\n";
    }
    return 0;
}