#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, kezd[105];
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> kezd[i];
    }
    for (int i=1; i<=n; i++) {
        int s, ert=kezd[i];
        cin >> s;
        for (int j=0; j<s; j++) {
            char c;
            cin >> c;
            if (c=='D') ert++;
            else ert--;
        }
        cout << ((ert%10+10)%10) << " ";
    }
    cout << "\n";
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