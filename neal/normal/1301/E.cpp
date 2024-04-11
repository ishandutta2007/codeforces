#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << "\"" << *vi << "\""; } os << "}"; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int INF = 1e9 + 5;
const int MAX = 505;

int N, M, Q;
vector<string> grid;
vector<vector<int>> max_logo;

void compute_maxes() {
    max_logo.assign(N, vector<int>(M, INF));
    vector<vector<int>> current;

    // Red
    current.assign(N + 1, vector<int>(M + 1, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (grid[i][j] == 'R')
                current[i + 1][j + 1] = min({current[i + 1][j], current[i][j + 1], current[i][j]}) + 1;

    dbg("Red", current);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            max_logo[i][j] = min(max_logo[i][j], current[i][j]);

    // Green
    current.assign(N + 1, vector<int>(M + 1, 0));

    for (int i = 0; i < N; i++)
        for (int j = M - 1; j >= 0; j--)
            if (grid[i][j] == 'G')
                current[i + 1][j] = min({current[i][j], current[i + 1][j + 1], current[i][j + 1]}) + 1;

    dbg("Green", current);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            max_logo[i][j] = min(max_logo[i][j], current[i][j]);

    // Blue
    current.assign(N + 1, vector<int>(M + 1, 0));

    for (int i = N - 1; i >= 0; i--)
        for (int j = M - 1; j >= 0; j--)
            if (grid[i][j] == 'B')
                current[i][j] = min({current[i + 1][j], current[i][j + 1], current[i + 1][j + 1]}) + 1;

    dbg("Blue", current);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            max_logo[i][j] = min(max_logo[i][j], current[i][j]);

    // Yellow
    current.assign(N + 1, vector<int>(M + 1, 0));

    for (int i = N - 1; i >= 0; i--)
        for (int j = 0; j < M; j++)
            if (grid[i][j] == 'Y')
                current[i][j + 1] = min({current[i + 1][j + 1], current[i][j], current[i + 1][j]}) + 1;

    dbg("Yellow", current);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            max_logo[i][j] = min(max_logo[i][j], current[i][j]);

    dbg(max_logo);
}

int16_t row_max[MAX][MAX][MAX];

void compute_ranges() {
    pair<int, int> q[MAX];

    for (int row = 0; row < N; row++)
        for (int c_start = 0; c_start < M; c_start++) {
            int start = 0, end = 0;

            for (int c = c_start + 1; c <= M; c++) {
                int option = min(max_logo[row][c - 1], c - 1 - c_start);

                if (start == end || option > q[end - 1].first)
                    q[end++] = {option, c - 1};

                while (end - start >= 2 && min(q[start].first, c - q[start].second) <= min(q[start + 1].first, c - q[start + 1].second))
                    start++;

                row_max[row][c_start][c] = min(q[start].first, c - q[start].second);
            }
        }
}

int query(int r1, int c1, int r2, int c2) {
    int best = 0;

    for (int r = r1; r < r2; r++)
        best = max(best, min({(int) row_max[r][c1][c2], r - r1, r2 - r}));

    return 4 * best * best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    grid.resize(N);

    for (string &row : grid)
        cin >> row;

    compute_maxes();
    compute_ranges();

    for (int q = 0; q < Q; q++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--;
        cout << query(r1, c1, r2, c2) << '\n';
    }
}