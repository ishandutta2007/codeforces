#include <iostream>
#include <set>

using namespace std;

int n;
multiset<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    s.insert(0);
    for (int i = 1; i <= n; i++) {
        char t;
        int x;
        cin >> t >> x;
        if (t == '+') s.insert(x);
        if (t == '-') s.erase(s.find(x));
        if (t != '?') continue;
        int v = 0;
        for (int b = 30; b >= 0; b--) {
            if (x&(1<<b)) {
                int t = v;
                auto u = s.lower_bound(t);
                if (*u < v+(1<<b)) continue;
                v += (1<<b);
            } else {
                int t = v+(1<<b);
                auto u = s.lower_bound(t);
                if (u != s.end() && *u < v+(1<<b)*2) v += (1<<b);
            }
        }
        cout << (v^x) << "\n";
    }
}