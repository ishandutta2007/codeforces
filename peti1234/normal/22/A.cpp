#include <bits/stdc++.h>

using namespace std;
int n, t[102];
int main()
{
    cin >>n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=2; i<=n; i++) {
        if (t[i]>t[i-1]) {
            cout << t[i] << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}