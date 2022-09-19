#include <bits/stdc++.h>

using namespace std;
long long w, n, el, x, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        el=0, maxi=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            maxi=max(maxi, el*x);
            el=x;
        }
        cout << maxi << "\n";
    }
    return 0;
}