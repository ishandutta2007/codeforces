#include <bits/stdc++.h>

using namespace std;
int w, n, x;
long long o, o2, e, e2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x%2) {
                o2++;
                o+=abs(i-2*o2+1);
            } else {
                e2++;
                e+=abs(i-2*e2+1);
            }
        }
        long long mini=1e10;
        if ((n+1)/2==o2) {
            mini=min(mini, o);
        }
        if ((n+1)/2==e2) {
            mini=min(mini, e);
        }
        cout << (mini==1e10 ? -1 : mini) << "\n";
        o=o2=e=e2=0;
    }
    return 0;
}