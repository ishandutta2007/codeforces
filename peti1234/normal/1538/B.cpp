#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, sum, cnt, t[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sum=0, cnt=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        if (sum%n) {
            cout << -1 << "\n";
        } else {
            cnt=0;
            for (int i=1; i<=n; i++) {
                if (t[i]>sum/n) {
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}