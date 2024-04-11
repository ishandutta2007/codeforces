#include <bits/stdc++.h>

using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    if (n==2 && k==0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n==1) {
        cout << k << "\n";
    } else if (n==2) {
        cout << 0 << " " << k << "\n";
    } else {
        for (int i=0; i<n-3; i++) {
            cout << i << " ";
            k^=i;
        }
        int a=(1<<17), b=(1<<18);
        cout << a << " " << b << " " << (a^b^k) << "\n";
    }
    return 0;
}