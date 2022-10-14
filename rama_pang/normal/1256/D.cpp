#include <bits/stdc++.h>
#define int lint
using namespace std;
using lint = long long;
string s, t;
deque<int> zero;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Q; cin >> Q; while (Q--) {
        lint n, k; cin >> n >> k;
        cin >> s;
        while(s.size() > n) s.pop_back();
        zero.clear();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero.push_back(i);
        }
        lint cur = 0;
        t.clear();
        for (int i = 0; i < n; i++) t.push_back('1');

        while (zero.size()) {
            if (k >= zero.front() - cur) {
                k -= zero.front() - cur;
                zero.pop_front();
                cur++;
                t[cur - 1] = '0';
            } else {
                t[zero.front() - k] = '0';
                k = 0;
                zero.pop_front();
            }
        }

        cout << t << "\n";
    }
}