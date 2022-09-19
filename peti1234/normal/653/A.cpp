#include <bits/stdc++.h>

using namespace std;
int n, db[1005];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    for (int i=1; i<=1000; i++) {
        if (db[i-1] && db[i] && db[i+1]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}