#include <bits/stdc++.h>

using namespace std;
int n, maxi, s;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        maxi=0;
        for (int j=1; j<=n; j++) {
            int x;
            cin >> x;
            maxi=max(maxi, x);
        }
        if (maxi==n-1) {
            if (s) {
                maxi++;
            } else {
                s=1;
            }
        }
        cout << maxi << " ";
    }
    cout << "\n";
    return 0;
}