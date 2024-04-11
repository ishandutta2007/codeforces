#include <bits/stdc++.h>

using namespace std;
int n;
int t[201];
int main()
{
    cin >> n;

    for (int i=1; i<=2*n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+2*n+1);
    if (t[n]==t[n+1]) {
        cout << "NO" << endl;
    } else {
    cout << "YES";
    }
    return 0;
}