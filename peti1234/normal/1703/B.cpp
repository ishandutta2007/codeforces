#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, ans=0;
    cin >> n;
    ans=n;
    set<int> s;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        s.insert(c);
    }
    cout << ans+s.size() << "\n";
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}