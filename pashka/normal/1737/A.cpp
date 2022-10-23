#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        string res;
        for (int i = 0; i < k; i++) {
            int x = 0;
            while (cnt[x] > 0 && x < n / k) {
                cnt[x]--;
                x++;
            }
            res += (char)('a' + x);
        }
        cout << res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}