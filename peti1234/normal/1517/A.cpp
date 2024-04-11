#include <bits/stdc++.h>

using namespace std;
long long w, n, s=2050;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        if (n%s) {
            cout << -1 << "\n";
        } else {
            long long p=n/s, ans=0;
            while (p) {
                ans+=p%10;
                p/=10;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}