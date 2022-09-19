#include <bits/stdc++.h>

using namespace std;
int n;
int maxi=0;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        maxi=max(maxi, x);
    }
    cout << max(0, maxi-25) << endl;
    return 0;
}