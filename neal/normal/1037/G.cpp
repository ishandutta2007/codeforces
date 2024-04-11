#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 1e5 + 5;
const int LETTERS = 26;

struct interval {
    int left;
    bool type;
    int8_t c;

    interval(int _left = -1, bool _type = false, int _c = -1) : left(_left), type(_type), c(_c) {}

    bool operator<(const interval &other) const {
        return left < other.left;
    }
};

int N, M;
char S[N_MAX];

int next_c[N_MAX][LETTERS];
int prev_c[N_MAX][LETTERS];

int8_t left_next_SG[N_MAX][LETTERS];
int8_t right_prev_SG[N_MAX][LETTERS];
int8_t prefix_xor[N_MAX];

vector<interval> intervals[N_MAX];

int last_seen[LETTERS];
int seen_index = 0;

int solve_SG(int left, int right) {
    seen_index++;

    for (int c = 0; c < LETTERS; c++) {
        int prev = prev_c[right][c];

        if (prev < left)
            continue;

        int next = next_c[left][c];
        int SG = left_next_SG[left][c] ^ right_prev_SG[right][c];
        SG ^= prefix_xor[prev] ^ prefix_xor[next];
        last_seen[SG] = seen_index;
    }

    int SG = 0;

    while (SG < LETTERS && last_seen[SG] == seen_index)
        SG++;

    return SG;
}

int main() {
    scanf("%s", S);
    N = strlen(S);

    fill_n(prev_c[0], LETTERS, -1);

    for (int i = 0; i <= N; i++) {
        if (i > 0)
            prev_c[i][S[i - 1] - 'a'] = i - 1;

        for (int c = 0; c < LETTERS; c++) {
            if (i < N)
                prev_c[i + 1][c] = prev_c[i][c];

            if (prev_c[i][c] != -1)
                intervals[i].emplace_back(prev_c[i][c] + 1, true, c);
        }
    }

    fill_n(next_c[N], LETTERS, N);

    for (int i = N; i >= 0; i--) {
        if (i < N)
            next_c[i][S[i] - 'a'] = i;

        for (int c = 0; c < LETTERS; c++) {
            if (i > 0)
                next_c[i - 1][c] = next_c[i][c];

            if (next_c[i][c] != N)
                intervals[next_c[i][c]].emplace_back(i, false, c);
        }
    }

    for (int right = 0; right <= N; right++) {
        vector<interval> &lefts = intervals[right];
        sort(lefts.begin(), lefts.end());
    }

    prefix_xor[0] = 0;

    // Glorified interval Sprague-Grundy DP with prefix XORs computed along the way for O(1) range queries
    for (int right = 0; right <= N; right++) {
        for (auto it = intervals[right].rbegin(); it != intervals[right].rend(); it++) {
            int answer = solve_SG(it->left, right);

            if (it->type)
                right_prev_SG[right][it->c] = answer;
            else
                left_next_SG[it->left][it->c] = answer;
        }

        int c = S[right] - 'a';
        prefix_xor[right] = prefix_xor[max(prev_c[right][c], 0)] ^ right_prev_SG[right][c];
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        L--;
        puts(solve_SG(L, R) ? "Alice" : "Bob");
    }
}