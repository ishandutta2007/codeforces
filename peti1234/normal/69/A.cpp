#include <bits/stdc++.h>

using namespace std;
int n, t[4];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=3; j++) {
            int x;cin >> x;
            t[j]+=x;
        }
    }
    for (int i=1; i<=3; i++) {
        if (t[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}