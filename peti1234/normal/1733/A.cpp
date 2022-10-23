#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, k, t[105];
    long long sum=0;
    cin >> n >> k;
    for (int i=0; i<k; i++) t[i]=0;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t[i%k]=max(t[i%k], x);
    }
    for (int i=0; i<k; i++) {
        sum+=t[i];
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