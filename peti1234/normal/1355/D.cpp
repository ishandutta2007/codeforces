#include <bits/stdc++.h>

using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    if (2*n>k) cout << "No" << "\n";
    else {
        cout << "Yes" << "\n";
        for (int i=1; i<n; i++) cout << 2 << " ";
        cout << k+2-2*n << "\n";
        cout << 1 << "\n";
    }
    return 0;
}