// ./c-remembering-strings.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 20;
int N, M,
    C[MN][MN], dp[1<<MN];
string cs[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (auto i = 0; i < N; i++)
        cin >> cs[i];
    for (auto i = 0; i < N; i++)
        for (auto j = 0; j < M; j++)
            cin >> C[i][j];

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    int msub = 1<<N;
    for (auto i = 0; i < M; i++) {
        vector<int> group[26];
        for (auto j = 0; j < N; j++)
            group[cs[j][i]-'a'].push_back(j);
        int fmsk[26], fcost[26];
        for (auto j = 0; j < 26; j++) {
            int c = 0, m = 0, mxCost = 0;
            for (auto x : group[j]) {
                c += C[x][i];
                mxCost = max(mxCost, C[x][i]);
                m |= 1 << x;
            }
            fmsk[j] = m;
            fcost[j] = c - mxCost;
        }

        auto push = [&] (int idx, int v) { dp[idx] = min(dp[idx], v); };
        for (auto j = 0; j < msub; j++) {
            for (auto k = 0; k < N; k++)
                push(j | (1 << k), dp[j] + C[k][i]);
            for (auto k = 0; k < 26; k++)
                push(j | fmsk[k], dp[j] + fcost[k]);
        }
    }
    cout << dp[msub-1] << '\n';

    return 0;
}