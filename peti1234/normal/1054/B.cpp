#include <bits/stdc++.h>

using namespace std;
int n, maxi=-1;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x>maxi+1) {
            cout << i << "\n";
            return 0;
        }
        maxi=max(maxi, x);
    }
    cout << -1 << "\n";
    return 0;
}