#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, t[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    if (n==1) {
        cout << "1 1\n0\n1 1\n0\n1 1\n" << -t[1] << "\n";
        return 0;
    }
    cout << 1 << " " << 1 << "\n" << n-t[1] << "\n";
    t[1]=n;
    cout << 2 << " " << n << "\n";
    for (int i=2; i<=n; i++) {
        cout << (n-1)*(t[i]%n) << " ";
        t[i]+=(n-1)*(t[i]%n);
    }
    cout << "\n";
    cout << 1 << " " << n << "\n";
    for (int i=1; i<=n; i++) {
        cout << -t[i] << " ";
    }
    cout << "\n";
    return 0;
}