#include <bits/stdc++.h>

using namespace std;
int n, d, t[1005], ans;
int main()
{
    cin >> n >> d;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (abs(t[i]-t[j])<=d) {
                ans++;
            }
        }
    }
    cout << ans-n << "\n";
    return 0;
}