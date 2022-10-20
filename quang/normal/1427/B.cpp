#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k;
char s[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        cin >> (s + 1);
        vector<int> ls;
        int cur = 0;
        char last = 'L';
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'W') {
                ls.push_back(cur);
                res++;
                if (last == 'W') res++;
                cur = 0;
            } else {
                cur++;
            }
            last = s[i];
        }
        ls.push_back(cur);

        if (ls.size() == 1) {
            if (k) cout << 2 * k - 1 << '\n';
            else cout << 0 << '\n';
            continue;
        }
        multiset<int> s;
        for (int i = 1; i + 1 < ls.size(); i++) {
            s.insert(ls[i]);
        }
        while (k > 0 && !s.empty()) {
            if (k >= *s.begin()) {
                int num = *s.begin();
                s.erase(s.begin());
                if (num == 0) continue;
                k -= num;
                res += 2 * num + 1; 
            } else {
                res += k * 2;
                k = 0;
            }
        }
        // cout << ' ' << res << ' ' << k << endl;
        int now = min(k, ls[0]);
        k -= now;
        res += now * 2;
        now = min(k, ls.back());
        k -= now;
        res += now * 2;
        cout << res << '\n';
    }
    return 0;
}