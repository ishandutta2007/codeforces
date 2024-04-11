#include <bits/stdc++.h>

using namespace std;
int n, t[100005];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    if (t[n-2]+t[n-1]>t[n]) {
        cout << "YES\n";
        for (int i=1; i<n; i++) {
            cout << t[i] << " ";
            if (i==n-2) {
                cout << t[n] << " ";
            }
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}