#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, x, spec=0;
    long long sum=0;
    vector<int> sz;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (i==n) continue;
        sum+=x;
        if (x) spec=1;
        
        else if (spec) sum++;
    }
    cout << sum << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}