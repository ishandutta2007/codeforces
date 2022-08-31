#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s, t;
        cin >> s >> t;

        sort(s.begin(), s.end());
        if (t == "abc") {
            auto it0 = upper_bound(s.begin(), s.end(), 'a');
            auto it1 = upper_bound(s.begin(), s.end(), 'c');
            if (it0 != s.begin()) {
                reverse(it0, it1);
            }
        }

        cout << s << '\n';
    }
    return 0;
}