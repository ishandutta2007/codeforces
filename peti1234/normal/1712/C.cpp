#include <bits/stdc++.h>

using namespace std;
int t[200005];
set<int> s;
vector<int> sz;
void solve() {

    int n;
    bool f=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        while (sz.size()>0 && t[i]<sz.back()) {
            s.insert(sz.back());
            sz.pop_back();
        }
        sz.push_back(t[i]);
    }
    for (int i=n; i>=1; i--) {
        if (s.count(t[i])) {
            f=1;
        }
        if (f) {
            s.insert(t[i]);
        }
    }
    cout << s.size() << "\n";

    s.clear(), sz.clear();
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
3
3 3 2
*/