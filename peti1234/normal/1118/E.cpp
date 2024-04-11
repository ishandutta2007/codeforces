#include <bits/stdc++.h>

using namespace std;
long long n, k;
int main()
{
    cin >> n >> k;
    if (n>k*(k-1)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i=1; i<=k; i++) {
        for (int j=i+1; j<=k; j++) {
            cout << i << " " << j << "\n";
            n--;
            if (n) {
                cout << j << " " << i << "\n";
                n--;
            }
            if (!n) {
                return 0;
            }
        }
    }
    return 0;
}