#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve_test() {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(256);
        for (char c : s) {
            cnt[c]++;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c] == 1) {
                string res;
                res += c;
                cnt[c]--;
                for (char t = 'a'; t <= 'z'; t++) {
                    res += string(cnt[t], t);
                }
                cout << res << "\n";
                return;
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c] == n) {
                cout << s << "\n";
                return;
            }
        }
        char a = 'a';
        while (!cnt[a]) a++;
        char b = a + 1;
        while (!cnt[b]) b++;
        char c = b + 1;
        while (c <= 'z' && !cnt[c]) c++;
        if (cnt[a] >= 2 && cnt[a] <= 2 + (n - 2) / 2) {
            string res(n, '.');
            res[0] = res[1] = a;
            cnt[a] -= 2;
            for (int i = 3; i < n; i += 2) {
                if (cnt[a] > 0) {
                    cnt[a]--;
                    res[i] = a;
                }
            }
            cnt[a] = 0;
            char k = 'a';
            for (int i = 0; i < n; i++) {
                if (res[i] == '.') {
                    while (cnt[k] == 0) k++;
                    cnt[k]--;
                    res[i] = k;
                }
            }
            cout << res << "\n";
            return;
        }
        if (c <= 'z') {
            string res;
            res += a;
            res += b;
            cnt[a]--;
            cnt[b]--;
            while (cnt[a]) {
                res += a;
                cnt[a]--;
            }
            res += c;
            cnt[c]--;
            for (char k = 'a'; k <= 'z'; k++) {
                while (cnt[k]) {
                    res += k;
                    cnt[k]--;
                }
            }
            cout << res << "\n";
            return;
        }
        string res;
        res += a;
        res += string(cnt[b], b);
        res += string(cnt[a] - 1, a);
        cout << res << "\n";
    }
};


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve_test();
    }

    return 0;
}