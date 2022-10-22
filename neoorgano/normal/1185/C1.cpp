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
        /*while (!s.empty() && sum + x > m) {
            sum -= *s.rbegin();
            auto el = s.end();
            el--;
            s1.insert(*el);
            s.erase(el);
            cnt++;
        }
        while (!s1.empty() && sum + x + (*s1.begin()) <= m) {
            sum += (*s1.begin());
            auto el = s1.begin();
            s.insert(*el);
            s1.erase(el);
            cnt--;
        }*/
        sum = 0;
        cnt = i;
        while (!s.empty() && sum + (*s.begin()) + x <= m) {
            sum += (*s.begin());
            s1.insert(*s.begin());
            s.erase(s.begin());
            cnt--;
        }
        while (!s1.empty()) {
            s.insert(*s1.begin());
            s1.erase(s1.begin());
        }
        sum += x;
        s.insert(x);
        cout << cnt << " ";
    }
    return 0;
}