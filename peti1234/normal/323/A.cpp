#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    if (n%2) cout << -1 << "\n";
    else {
        for (int i=1; i<=n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    if ((i%2+(j/2)%2+(k/2)%2)%2) cout << "w";
                    else cout << "b";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
    return 0;
}