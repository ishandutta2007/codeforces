#include <bits/stdc++.h>

using namespace std;
int n;
int t[300001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (t[i]!=t[1] || t[n-i+1]!=t[1]) {
            cout << n-i << endl;
            return 0;
        }
    }
    return 0;
}