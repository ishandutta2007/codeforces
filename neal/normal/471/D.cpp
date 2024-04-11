#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

namespace KMP {
    // Returns the next length to search from after starting from `len` and adding char `c`.
    // Runs in worst case O(len) but amortizes to O(1) in most situations.
    template<typename T, typename T_elem>
    int get_link(const T &pattern, const vector<int> &fail, int len, const T_elem &c) {
        while (len > 0 && pattern[len] != c)
            len = fail[len];

        if (pattern[len] == c)
            len++;

        return len;
    }

    // Computes the failure function on `pattern` so that we can search for it in future strings.
    template<typename T>
    vector<int> compute_failure_function(const T &pattern) {
        // fail[i] = for the prefix [0, i) of `pattern`, the length of the longest proper prefix that is also a suffix.
        int n = int(pattern.size());
        vector<int> fail(n + 1, 0);
        int len = 0;

        for (int i = 1; i < n; i++) {
            len = get_link(pattern, fail, len, pattern[i]);
            fail[i + 1] = len;
        }

        return fail;
    }

    template<typename T>
    vector<int> find_matches(const T &pattern, const T &text, const vector<int> &fail) {
        if (pattern.size() > text.size())
            return {};

        vector<int> matches;
        int n = int(pattern.size()), m = int(text.size());
        int len = 0;

        for (int i = 0; i < m; i++) {
            len = get_link(pattern, fail, len, text[i]);

            // Check for a match whose last character is at index i.
            if (len == n) {
                matches.push_back(i - (n - 1));
                len = fail[len];
            }
        }

        return matches;
    }

    // Finds all indices where `pattern` occurs within `text`.
    template<typename T>
    vector<int> find_matches(const T &pattern, const T &text) {
        return find_matches(pattern, text, compute_failure_function(pattern));
    }
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, W;
    cin >> N >> W;
    vector<int> A(N), B(W);

    if (W == 1) {
        cout << N << '\n';
        return 0;
    }

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    for (int i = 0; i < N - 1; i++)
        A[i] = A[i + 1] - A[i];

    for (int i = 0; i < W - 1; i++)
        B[i] = B[i + 1] - B[i];

    A.pop_back();
    N--;
    B.pop_back();
    W--;
    cout << KMP::find_matches(B, A).size() << '\n';
}