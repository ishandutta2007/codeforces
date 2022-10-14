/*  Turn this problem into a DP.
    Observe that a subtree of either Lower or Upper
    will be connected to a contiguous segment.

    Thus we can find the maximum number of edges removable
    for all segments (l, r).

    To compute it, if we know cost(l, r - 1), we can find
    cost(l, r) by going up from node r while the current
    remaining degrees of its ancestor is one. Otherwise,
    decrease degree and stop.

    Thus upperCost(l, r) and lowerCost(l, r) can be found in
    O(N * N).

    Then do a standard DP, with transitions:
    dp(n) = dp(k) + cost(k + 1, n) for k < n
    This takes O(N * N).

    Thus the total time complexity is O(N * N).

*/

#include <bits/stdc++.h>
// #define LOCAL
using namespace std;

vector<vector<int>> get_cost(int N, int n, vector<int> id, vector<int> p) {
    vector<vector<int>> cost(N, vector<int>(N, 0));
    for (int l = 0; l < N; l++) {
        vector<int> deg(n, 0);
        int last = 0;
        for (auto i : p) if (i != -1) deg[i]++;

        for (int r = l; r < N; r++) {
            int v = id[r];
            int k = 0;
            while (v != -1 && p[v] != -1 && deg[v] == 0) {
                deg[p[v]]--;
                k++;
                v = p[v];
            }
            cost[l][r] = k + last;
            last = cost[l][r];
        }
    }

    return cost;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;
    array<vector<vector<int>>, 2> cost;

    for (int i = 0; i < 2; i++) {
        int n; cin >> n;
        vector<int> p(n, -1);
        vector<int> id(N, -1);
        for (int j = 1; j < n; j++) {
            cin >> p[j];
            p[j]--;
        }

        for (int j = 0; j < N; j++) {
            cin >> id[j];
            id[j]--;
        }

        cost[i] = get_cost(N, n, id, p);

        #ifdef LOCAL
        cout << "COST:\n";
        for (int j = 0; j < N; j++) {
            for (int k = j; k < N; k++) {
                cout << j << " " << k << " " << cost[i][j][k] << "\n"; 
            }
        }
        cout << "\n";
        #endif
    }

    vector<int> DP(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int dp = (j > 0)? DP[j - 1] : 0;
            int cs = max(cost[0][j][i], cost[1][j][i]);
            DP[i] = max(DP[i], dp + cs);
        }
    }

    cout << DP[N - 1] << "\n";

    return 0;

}