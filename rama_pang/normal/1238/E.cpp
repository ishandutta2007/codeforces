#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int N, M;
    cin >> N >> M;
    string s; cin >> s;
    vector<vector<int>> cnt(M, vector<int>(M, 0));
 
    for (int i = 1; i < N; i++) {
        cnt[s[i - 1] - 'a'][s[i] - 'a']++;
        cnt[s[i] - 'a'][s[i - 1] - 'a']++;
    }
 
    vector<int> DP(1 << M, (int)1e9);
    DP[0] = 0;
    for (int mask = 0; mask < (1 << M); mask++) { // alphabet already picked - popcount is current keyboard index
        int BIT = __builtin_popcount(mask);
        for (int nxt = 0; nxt < M; nxt++) { // next alphabet to be picked
            if (mask & (1 << nxt)) continue; // already picked that alphabet
            int cost = 0;
            for (int j = 0; j < M; j++) { // place the alphabet, subtract from future pairs to get distance
                if (nxt == j) continue;
                if (mask & (1 << j)) {
                    cost += cnt[j][nxt];
                } else {
                    cost -= cnt[j][nxt];
                }
            }
            cost *= BIT;
            DP[mask | (1 << nxt)] = min(DP[mask | (1 << nxt)], DP[mask] + cost);
        }
    }
 
    cout << DP[(1 << M) - 1] << "\n";
    return 0;
}