#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long n, k, b, s;
    cin >> n >> k >> b >> s;
    long long kis=k*b, nagy=k*b+n*(k-1);
    if (s<kis || nagy<s) {
        cout << -1 << "\n";
        return;
    }
    long long dif=s-kis;
    for (int i=1; i<=n; i++) {
        long long ert=0;
        ert+=min(dif, k-1);
        dif-=ert;
        if (i==1) ert+=k*b;
        cout << ert << " ";
    }
    cout << "\n";
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