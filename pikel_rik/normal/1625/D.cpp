#include <bits/stdc++.h>
using namespace std;

template<int N>
struct bitwise_trie {
    struct node {
        int cnt;
        std::array<int, 2> next;

        node() : cnt(0) {
            next.fill(-1);
        }
    };

    std::vector<node> t;

    bitwise_trie() : t(1) {}

    void insert(const std::bitset<N> &b) {
        int cur = 0;
        t[cur].cnt += 1;
        for (int i = N - 1; i >= 0; i--) {
            if (t[cur].next[b[i]] == -1) {
                t[cur].next[b[i]] = (int) t.size();
                t.emplace_back();
            }
            cur = t[cur].next[b[i]];
            t[cur].cnt += 1;
        }
    }

    std::bitset<N> xor_maximum(std::bitset<N> b) {
        assert(t[0].cnt > 0);
        int cur = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (t[cur].next[!b[i]] != -1 && t[t[cur].next[!b[i]]].cnt > 0) {
                cur = t[cur].next[!b[i]];
                b.set(i);
            } else {
                cur = t[cur].next[b[i]];
                b.reset(i);
            }
        }
        return b;
    }

    node &operator[](int i) {
        return t[i];
    }

    const node &operator[](int i) const {
        return t[i];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    }

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int lg = 32 - __builtin_clz(k);

    map<int, vector<int>> split;
    for (int i = 0; i < n; i++) {
        split[a[i] >> lg].push_back(i);
    }

    vector<int> ans;
    ans.reserve(n);

    for (auto &[x, v] : split) {
        bitwise_trie<30> t;
        map<int, int> mp;

        bool found_pair = false;
        for (int i : v) {
            if (t[0].cnt > 0) {
                int xor_max = t.xor_maximum(a[i]).to_ulong();
                int other_num = a[i] ^ xor_max;
                if (xor_max >= k) {
                    ans.push_back(i);
                    ans.push_back(mp[other_num]);
                    found_pair = true;
                    break;
                }
            }
            t.insert(a[i]);
            mp[a[i]] = i;
        }

        if (!found_pair) {
            ans.push_back(v.front());
        }
    }

    if (ans.size() <= 1) {
        cout << "-1\n";
    } else {
        cout << (int) ans.size() << '\n';
        for (int i : ans) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}