#include <bits/stdc++.h>

using namespace std;
int n, t[105];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}