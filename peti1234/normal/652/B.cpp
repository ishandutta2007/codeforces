#include <bits/stdc++.h>

using namespace std;
int n, a[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i=1; i<=n/2; i++) {
        cout << a[i] << " " << a[n-i+1] << " ";
    }
    if (n%2) {
        cout << a[(n+1)/2] << " ";
    }
    cout << "\n";
    return 0;
}