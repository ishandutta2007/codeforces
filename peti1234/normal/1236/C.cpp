#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<n/2; j++) {
            cout << j*n+i << " ";
        }
        for (int j=n/2; j<n; j++) {
            cout << j*n+n+1-i << " ";
        }
        cout << "\n";
    }
    return 0;
}