#include <bits/stdc++.h>

using namespace std;
long long t[500005];

void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    long long sum=0, kezd=0;
    for (int i=1; i<=n; i++) {
        kezd=max(kezd, i-t[i]);
        sum+=i-kezd;
    }
    cout << sum << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}