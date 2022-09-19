#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, maxi=0, x;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> x;
            maxi=max(maxi, x-i);
        }
        cout << maxi << "\n";
    }
    return 0;
}