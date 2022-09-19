#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, a[c], b[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        bool baj=0;
        long long mini=0, maxi=2e9;
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            if (a[i]-mini<b[i] && b[i]) baj=1;
            mini=max(mini, a[i]-b[i]);
            if (b[i]) maxi=min(maxi, a[i]-b[i]);
        }
        if (mini>maxi) baj=1;
        cout << (baj ? "NO" : "YES") << "\n";

    }
    return 0;
}
/*
6
6 3
3 2 7 1 4 8
1
4 3
2 1 5 6
*/