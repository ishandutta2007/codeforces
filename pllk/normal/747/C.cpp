#include <iostream>
#include <set>

using namespace std;

int n, q;
set<int> v;
set<pair<int,int>> r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) v.insert(i);
    for (int i = 0; i < q; i++) {
        int t, k, d;
        cin >> t >> k >> d;
        while (r.size() > 0) {
            auto it = r.begin();
            if (it->first <= t) {
                v.insert(it->second);
                r.erase(it);
            } else break;
        }
        if (v.size() < k) {
            cout << "-1\n";
            continue;
        }
        int u = 0;
        for (int i = 1; i <= k; i++) {
            auto it = v.begin();
            u += *it;
            r.insert({t+d,*it});
            v.erase(it);
        }
        cout << u << "\n";
    }
}