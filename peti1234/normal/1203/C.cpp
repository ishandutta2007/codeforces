#include <bits/stdc++.h>

using namespace std;
long long n, x, ert, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        ert=__gcd(ert, x);
    }
    for (long long i=1; i*i<=ert; i++) {
        if (ert%i==0) {
            ans++;
            if (i*i!=ert) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}