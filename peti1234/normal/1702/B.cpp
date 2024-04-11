#include <bits/stdc++.h>

using namespace std;
void solve() {
    string s;
    cin >> s;
    set<int> p;
    int ans=1, cnt=0;
    for (auto x:s) {
        if (p.find(x)==p.end()) cnt++;
        if (cnt==4) {
            p.clear();
            ans++;
            cnt=1;
        }
        p.insert(x);
    }
    cout << ans << "\n";
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
/*
1
stringology
*/