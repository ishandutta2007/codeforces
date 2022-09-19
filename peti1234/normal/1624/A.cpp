#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        int x, mini, maxi;
        cin >> x;
        maxi=mini=x;
        for (int i=1; i<n; i++) {
            cin >> x;
            maxi=max(maxi, x);
            mini=min(mini, x);
        }
        cout << maxi-mini << "\n";
    }
    return 0;
}