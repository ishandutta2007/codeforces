#include <bits/stdc++.h>

using namespace std;
int n, t[100002], xo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        xo^=t[i];
    }
    if (n%2==0 && xo!=0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n%2==0) n--;
    cout << n-1 << "\n";
    for (int i=1; i<=n-2; i+=2) {
        cout << i << " " << i+1 << " " << i+2 << "\n";
    }
    for (int i=1; i<=n-2; i+=2) {
        cout << i << " " << i+1 << " " << n << "\n";
    }
    return 0;
}