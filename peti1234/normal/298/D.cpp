#include <bits/stdc++.h>

using namespace std;
multiset<int> s;
int main()
{
    s.insert(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        auto it=s.upper_bound(x);
        it--;
        if ((*it)!=0) {
            s.erase(it);
        }
    }
    cout << (s.size()>1 ? "YES" : "NO") << "\n";
    return 0;
}