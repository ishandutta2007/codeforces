#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, n, mini=1e5, c, d;
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++) {
        cin >> c >> d;
        int sa=a, sb=b, cnt=0;
        while (sa!=c || sb!=d) {
            if (sb<60) sb++;
            if (sb==60) sb=0, sa++;
            if (sa==24) sa=0;
            cnt++;
        }
        mini=min(mini, cnt);
    }
    cout << mini/60 << " " << mini%60 << "\n";
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