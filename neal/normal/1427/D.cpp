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


int main() {
    int N;
    cin >> N;
    vector<int> cards(N);

    for (auto &c : cards)
        cin >> c;

    vector<vector<int>> operations;

    auto apply_op = [&](vector<bool> is_start) {
        vector<int> op;
        vector<vector<int>> chunks;
        int start = 0;

        for (int i = 0; i <= N; i++)
            if (is_start[i] && i > start) {
                chunks.push_back(vector<int>(cards.begin() + start, cards.begin() + i));
                op.push_back(i - start);
                start = i;
            }

        operations.push_back(op);
        reverse(chunks.begin(), chunks.end());
        cards = {};

        for (auto &chunk : chunks)
            cards.insert(cards.end(), chunk.begin(), chunk.end());

        assert(int(cards.size()) == N);
    };

    for (int x = 1; x < N; x++) {
        vector<bool> is_start(N + 1, false);
        is_start[0] = is_start[N] = true;

        // 1 ... x are either 1, ..., x or x, 1, ... x-1; want to add in x+1.
        int where_x = int(find(cards.begin(), cards.end(), x) - cards.begin());
        int where_1 = int(find(cards.begin(), cards.end(), 1) - cards.begin());
        int where_x1 = int(find(cards.begin(), cards.end(), x - 1) - cards.begin());

        if (where_x + 1 == where_1) {
            is_start[where_x] = true;
            is_start[where_1] = true;
            is_start[where_x1 + 1] = true;
        } else {
            is_start[where_1] = true;
            is_start[where_x + 1] = true;
        }

        where_x1 = int(find(cards.begin(), cards.end(), x + 1) - cards.begin());

        if (where_x1 < where_1)
            is_start[where_x1] = true;
        else
            is_start[where_x1 + 1] = true;

        apply_op(is_start);
    }

    if (N > 1 && cards.front() == N) {
        vector<bool> is_start(N + 1, false);
        is_start[0] = is_start[1] = is_start[N] = true;
        apply_op(is_start);
    }

    assert(int(operations.size()) <= N);
    cout << operations.size() << '\n';

    for (auto &op : operations) {
        cout << op.size();

        for (int x : op)
            cout << ' ' << x;

        cout << '\n';
    }
}