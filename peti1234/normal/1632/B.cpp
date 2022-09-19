#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        int ert=1;
        while (2*ert<n) ert*=2;
        for (int i=ert-1; i>=0; i--) cout << i << " ";
        for (int i=ert; i<n; i++) cout << i << " ";
        cout << "\n";
    }
    return 0;
}