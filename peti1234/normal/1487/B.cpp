#include <bits/stdc++.h>

using namespace std;
long long w, n, k, ert;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> k;
        k--;
        ert=(k+1)%n;
        if (n%2) {
            ert+=k/(n/2);
            ert%=n;
        }
        cout << (ert? ert : n) << "\n";
    }
    return 0;
}