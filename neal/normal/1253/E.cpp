#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}

const int INF = 1e9 + 5;
const int N_MAX = 82;
const int M_MAX = 1e5 + 5;

struct antenna {
    int x, s;

    bool operator<(const antenna &other) const {
        return x < other.x;
    }
};

int N, M;
vector<antenna> antennas;
int dp[N_MAX][M_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    antennas.resize(N);

    for (auto &ant : antennas)
        cin >> ant.x >> ant.s;

    sort(antennas.begin(), antennas.end());
    memset(dp, 63, sizeof(dp));

    for (int i = 0; i < N; i++)
        for (int s = antennas[i].x - 1; s <= M; s++)
            dp[i][s] = max(s - antennas[i].s, 0);

    for (int i = 0; i < N; i++) {
        for (int s = M - 1; s >= 0; s--)
            minimize(dp[i][s], dp[i][s + 1]);

        for (int s = 0; s < M; s++)
            minimize(dp[i][s + 1], dp[i][s] + 1);

        for (int s = 0; s <= M; s++)
            if (dp[i][s] < INF)
                for (int j = i + 1; j < N; j++) {
                    int diff = antennas[j].x - (antennas[i].x + s + 1);
                    int need = max(diff - antennas[j].s, 0);
                    minimize(dp[j][max(antennas[j].s, diff)], dp[i][s] + need);
                }
    }

    int best = INF;

    for (int i = 0; i < N; i++)
        for (int s = 0; s <= M; s++)
            if (antennas[i].x + s >= M)
                minimize(best, dp[i][s]);

    cout << best << '\n';
}