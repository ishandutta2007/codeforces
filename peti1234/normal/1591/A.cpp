#include <bits/stdc++.h>

using namespace std;
int w, n, sum, el, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sum=1, el=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x) {
                sum+=x+4*el;
            }
            if (!x && !el && i>1) {
                sum-=1e9;
            }
            el=x;
        }
        cout << max(-1, sum) << "\n";
    }
    return 0;
}