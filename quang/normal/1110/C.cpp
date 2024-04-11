#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

set<int> s;
int pref[] = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int get(int u) {
    int res = 1;
    for (int i = 1; i < u; i++) {
        res = max(res, __gcd(i & u, i ^ u));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 30; i++) {
        s.insert(1 << i);
    }
    // for (int i = 2; i <= 25; i++) {
    //     cout << get((1 << i) - 1) << ", ";
    // }
    // cout << endl;
    int q;
    cin >> q;
    while (q--) {
        int u;
        cin >> u;
        if (s.count(u + 1)) {
            int foo = log2(u + 1);
            cout << pref[foo] << endl;
        }
        else cout << *s.upper_bound(u) - 1 << endl;
    }
    return 0;
}