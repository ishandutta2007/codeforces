#include <bits/stdc++.h>
using namespace std;

template<typename string_t>
std::vector<int> prefix_function(const string_t &s, int n = -1) {
    if (n == -1) {
        n = (int) s.size();
    }
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            pi[i] = j + 1;
        }
    }
    return pi;
}

template<char f = 'a', int K = 26>
struct trie {
    struct node {
        int best;
        std::array<int, K> next;

        node() : best(0) {
            next.fill(-1);
        }
    };

    std::vector<node> t;

    trie() : t(1) {}

    void insert(const std::string &s, int value) {
        int cur = 0;
        for (char ch: s) {
            if (t[cur].next[ch - f] == -1) {
                t[cur].next[ch - f] = (int) t.size();
                t.emplace_back();
            }
            cur = t[cur].next[ch - f];
            t[cur].best = max(t[cur].best, value);
        }
    }

    int search(const std::string &s) {
        int cur = 0;
        for (char ch : s) {
            if (t[cur].next[ch - f] == -1) {
                return 0;
            }
            cur = t[cur].next[ch - f];
        }
        return t[cur].best;
    }

    node &operator[](int i) {
        return t[i];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = (int) s.length();

    if (n <= 10) {
        int q;
        cin >> q;

        while (q--) {
            string t;
            cin >> t;

            int m = (int) t.length();

            string u = s + t;

            auto pi = prefix_function(u);

            for (int i = n; i < m + n; i++) {
                cout << pi[i] << ' ';
            }
            cout << '\n';
        }

        return 0;
    }

    auto pi = prefix_function(s);

    trie tree;

    vector<bool> ps(n + 1);
    for (int i = pi[n - 1];; i = pi[i - 1]) {
        ps[i] = true;
        int j = min(10, n - i);
        tree.insert(s.substr(i, j), i);
        if (i == 0) {
            break;
        }
    }

    int q;
    cin >> q;

    while (q--) {
        string t;
        cin >> t;

        int m = (int) t.length();

        auto pii = prefix_function(t);

        for (int i = 0; i < m; i++) {
            int mx = tree.search(t.substr(0, i + 1));
            if (mx > 0) {
                mx += i + 1;
            }
            for (int j = pii[i]; j > 0; j = pii[j - 1]) {
                if (t.substr(0, i - j + 1) == s.substr(n - (i - j + 1)) && ps[n - (i - j + 1)]) {
                    mx = max(mx, n + j);
                    break;
                }
            }
            for (int j = 0; j <= i; j++) {
                bool match = true;
                for (int k = j; k <= i; k++) {
                    match &= s[k - j] == t[k];
                }
                if (match) {
                    mx = max(mx, i - j + 1);
                    break;
                }
            }
            cout << mx << ' ';
        }
        cout << '\n';
    }
    return 0;
}