#include <bits/stdc++.h>
using namespace std;

main() {
    int n, m;
    cin >> n >> m;
    multiset<int> s, s1;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n ;++i) {
        int x;
        cin >> x;
        while (!s1.empty() && !s.empty() && (*s1.begin()) < (*s.rbegin())) {
            auto el = s1.begin();
            s.insert(*el);
            sum += *el;
            s1.erase(el);
            auto el2 = s.end();
            el2--;
            s1.insert(*el2);
            sum -= *el2;
            s.erase(el2);
        }
        // cout << s1.size() << endl;
        while (!s.empty() && sum + x > m) {
            auto el = s.end();
            el--;
            sum -= *el;
            s1.insert(*el);
            s.erase(el);
        }
        // hcout << s1.size() << endl;
        while (!s1.empty() && sum + x + (*s1.begin()) <= m) {
            auto el = s1.begin();
            sum += *el;
            s.insert(*el);
            s1.erase(el);
        }
        s1.insert(x);
        cout << s1.size() - 1 << " ";
    }
    return 0;
}