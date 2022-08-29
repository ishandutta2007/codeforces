#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct painter {
    int L, R;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    cin >> N >> P;
    vector<painter> painters(P);

    for (int i = 0; i < P; i++) {
        cin >> painters[i].L >> painters[i].R;
        painters[i].L--;
    }

    vector<vector<int>> painters_at(N + 1, vector<int>());

    for (int i = 0; i < P; i++)
        for (int x = painters[i].L; x < painters[i].R; x++)
            if (painters_at[x].size() <= 2)
                painters_at[x].push_back(i);

    vector<int> single_count(P, 0);
    vector<vector<int16_t>> pair_count(P, vector<int16_t>(P, 0));
    int painted = 0;

    for (int x = 0; x < N; x++) {
        if (!painters_at[x].empty())
            painted++;

        if (painters_at[x].size() == 1) {
            single_count[painters_at[x][0]]++;
        } else if (painters_at[x].size() == 2) {
            int a = painters_at[x][0], b = painters_at[x][1];
            pair_count[a][b]++;
            pair_count[b][a]++;
        }
    }

    int best = 0;

    for (int a = 0; a < P; a++)
        for (int b = a + 1; b < P; b++)
            best = max(best, painted - single_count[a] - single_count[b] - pair_count[a][b]);

    cout << best << '\n';
}