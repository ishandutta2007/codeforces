#include <bits/stdc++.h>

using namespace std;
int w, n, x, sum, el, ut;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> x, el=0, ut=0, sum=0;
        for (int i=1; i<=n; i++) {
            int p;
            cin >> p;
            sum+=p;
            if (p%x && !el) el=i;
            if (p%x) ut=i;
        }
        if (sum%x) cout << n << "\n";
        else if (el) cout << max(n-el, ut-1) << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}