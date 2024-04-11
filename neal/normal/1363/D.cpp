#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> S(K + 1);
    vector<bool> seen(N, false);

    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        S[i].resize(c);

        for (int &x : S[i]) {
            cin >> x;
            x--;
            seen[x] = true;
        }
    }

    for (int i = 0; i < N; i++)
        if (!seen[i])
            S[K].push_back(i);

    auto &&query = [&](const vector<bool> &subsets) {
        assert(int(subsets.size()) == K + 1);
        vector<int> ask;

        for (int k = 0; k <= K; k++)
            if (subsets[k])
                ask.insert(ask.end(), S[k].begin(), S[k].end());

        if (ask.empty())
            return -1;

        cout << "? " << ask.size();

        for (int x : ask)
            cout << ' ' << x + 1;

        cout << endl;
        int result;
        cin >> result;
        return result;
    };

    auto &&answer = [&](const vector<int> &password) {
        cout << "!";

        for (int x : password)
            cout << ' ' << x;

        cout << endl;
        string result;
        cin >> result;
        assert(result == "Correct");
    };

    vector<bool> subsets(K + 1, true);
    int maximum = query(subsets);
    int max_bits = 0;

    for (int bit = 0; 1 << bit <= K; bit++) {
        for (int k = 0; k <= K; k++) {
            bool match = true;

            for (int i = 0; i <= bit; i++)
                if ((k >> i & 1) != (max_bits >> i & 1))
                    match = false;

            subsets[k] = match;
        }

        int current = query(subsets);

        if (current < maximum)
            max_bits |= 1 << bit;
    }

    for (int k = 0; k <= K; k++)
        subsets[k] = k != max_bits;

    int non_maximum = query(subsets);
    vector<int> password(K);

    for (int k = 0; k < K; k++)
        password[k] = k == max_bits ? non_maximum : maximum;

    answer(password);
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}