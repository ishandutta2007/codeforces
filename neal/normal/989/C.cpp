#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int ROWS = 12, COLS = 50;

int main() {
    int N[4];
    cin >> N[0] >> N[1] >> N[2] >> N[3];
    vector<string> grid(4 * ROWS, string(COLS, '.'));

    for (int r = 0; r < 4 * ROWS; r++)
        for (int c = 0; c < COLS; c++)
            grid[r][c] = 'A' + r / ROWS;

    for (int n = 0; n < 4; n++) {
        int next = (n + 1) % 4;
        int count = N[next] - 1;

        for (int i = 0; i < count; i++) {
            int row = n * ROWS + 2 * (i / (COLS / 2));
            int col = 2 * (i % (COLS / 2));
            grid[row][col] = 'A' + next;
        }
    }

    cout << 4 * ROWS << ' ' << COLS << '\n';

    for (string &row : grid)
        cout << row << '\n';
}