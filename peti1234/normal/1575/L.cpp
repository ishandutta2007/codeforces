#include <bits/stdc++.h>

using namespace std;
int n, x;
multiset<int> s;
vector<pair<int, int> > sz;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x<=i) {
            sz.push_back({i-x, x});
        }
    }
    sort(sz.begin(), sz.end());
    for (auto p:sz) {
        int x=p.second;
        if (s.lower_bound(x)!=s.end()) {
            s.erase(s.lower_bound(x));
        }
        s.insert(x);
    }
    cout << s.size() << "\n";
    return 0;
}