#include <bits/stdc++.h>

using namespace std;
int w;
long long n, ert, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, ert=n-1, s=ert*ert;
        for (int j=1; j<=n-2; j++) {
            ert-=j%2;
            s+=ert*ert;
        }
        cout << s << endl;
        if (n%2) {
            cout << (n+1)/2 << " ";
            for (int i=1; i<n/2; i++) {
                cout << i << " ";
            }
            for (int i=n/2+2; i<=n; i++) {
                cout << i << " ";
            }
            cout << n/2 << "\n";
            cout << n-1 << "\n";
            for (int i=1; i<=n/2; i++) {
                cout << n/2+i << " " << 1 << "\n";
            }
            for (int i=1; i<n/2; i++) {
                cout << n/2+1-i << " " << n << "\n";
            }
            if (n!=1) cout << 1 << " " << n << "\n";
        } else {
            cout << n/2+1 << " ";
            for (int i=1; i<n/2; i++) {
                cout << i << " ";
            }
            for (int i=n/2+2; i<=n; i++) {
                cout << i << " ";
            }
            cout << n/2 << "\n";
            cout << n-1 << "\n";
            for (int i=1; i<n/2; i++) {
                cout << n/2+i  << " " << 1 << "\n";
            }
            for (int i=1; i<n/2; i++) {
                cout << n/2+1-i << " " << n << "\n";
            }
            cout << 1 << " " << n << "\n";
        }
    }
    return 0;
}