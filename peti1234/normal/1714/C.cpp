#include <bits/stdc++.h>

using namespace std;

void solve() {
    int s;
    cin >> s;
    vector<int> sz;
    for (int i=9; i>=1; i--) {
        if (s>=i) sz.push_back(i), s-=i;
    }
    reverse(sz.begin(), sz.end());
    for (auto x:sz) cout << x;
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