#include <bits/stdc++.h>

using namespace std;
int n;
int t[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    if (n%2!=0 && t[1]%2!=0 && t[n]%2!=0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}