#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const string DIGITS[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
// const int COUNTS[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int count_ones(string str) {
    int ones = 0;

    for (char c : str)
        ones += c - '0';

    return ones;
}

bool can_create(string digit, int d) {
    for (int i = 0; i < 7; i++)
        if (digit[i] > DIGITS[d][i])
            return false;

    return true;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> board(N);

    for (string &digit : board)
        cin >> digit;

    vector<vector<bool>> possible(N + 1, vector<bool>(K + 1, false));
    possible[N][0] = true;

    for (int i = N - 1; i >= 0; i--)
        for (int d = 0; d < 10; d++)
            if (can_create(board[i], d)) {
                int add = count_ones(DIGITS[d]) - count_ones(board[i]);

                for (int k = 0; k <= K; k++)
                    possible[i][k] = possible[i][k] || (k >= add && possible[i + 1][k - add]);
            }

    if (!possible[0][K]) {
        cout << -1 << '\n';
        return 0;
    }

    string answer(N, '.');

    for (int i = 0; i < N; i++) {
        assert(possible[i][K]);

        for (int d = 9; d >= 0; d--)
            if (can_create(board[i], d)) {
                int add = count_ones(DIGITS[d]) - count_ones(board[i]);

                if (K >= add && possible[i + 1][K - add]) {
                    answer[i] = '0' + d;
                    K -= add;
                    break;
                }
            }
    }

    cout << answer << '\n';
}