// ./c-minimum-ties.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 101;
int st[MN][MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int take = N*(N-1)/2;
        take -= take % N;
        int needCnt = take / N;

        memset(st, 0, sizeof st);

        vector<int> cnt(N), deg(N, N-1);
        if (N % 2 == 0)
            for (auto &x : deg) x--;

        for (auto i = 0; i < N; i++) {
            for (auto j = 0; j < N; j++) {
                if (i == j) continue;

                int a = i, b = j, m = 1;
                if (a > b) { swap(a, b); m = -1; }

                // reserve "main cycle" edges
                if (N % 2 == 0 && a + 1 == b && a % 2 == 0 && b % 2 == 1) continue;

                // don't take if not possible
                if (deg[j] + cnt[j] - 1 < needCnt) continue;

                if (!st[a][b] && cnt[i] < needCnt) {
                    cnt[i]++;
                    st[a][b] = m;
                    deg[a]--; deg[b]--;
                }
            }
        }
        // printf("cnt=");
        // for (auto &x : cnt) {
        //     printf("%d ", x);
        // }
        // printf("\n");

        for (auto &x : cnt) assert(x == needCnt);
        for (auto i = 0; i < N; i++) {
            for (auto j = i+1; j < N; j++) {
                if (st[i][j] == 1) cnt[i]--;
                if (st[i][j] == -1) cnt[j]--;
            }
        }
        for (auto &x : cnt) assert(x == 0);

        for (auto i = 0; i < N; i++)
            for (auto j = i+1; j < N; j++)
                cout << st[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}