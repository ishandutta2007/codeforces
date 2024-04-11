#include <bits/stdc++.h>

using namespace std;
int n, t[105];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                if (t[i]+t[j]==t[k]) {
                    cout << k << " " << i << " " << j << "\n";
                    return 0;
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}