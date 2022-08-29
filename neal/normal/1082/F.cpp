#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

template<typename T1, typename T2>
void maximize(T1 &a, const T2 &b) {
    if (b > a) {
        a = b;
    }
}

const int N_MAX = 505, K_MAX = 11;
const int ALPHABET = 10;

struct trie_node {
    int calls;
    int child[ALPHABET];
    int dp[N_MAX][K_MAX];

    trie_node() {
        calls = 0;
        memset(child, -1, sizeof(child));
        memset(dp, -1, sizeof(dp));
    }
};

int N, K;
vector<trie_node> trie;

int dfs(int node) {
    if (node < 0)
        return 0;

    for (int d = 0; d < ALPHABET; d++)
        trie[node].calls += dfs(trie[node].child[d]);

    return trie[node].calls;
}

int solve(int node, int dist, int k) {
    if (node < 0)
        return 0;

    int &answer = trie[node].dp[dist][k];

    if (answer >= 0)
        return answer;

    // Place a speed dial at this node.
    if (k > 0)
        maximize(answer, dist * trie[node].calls + solve(node, 0, k - 1));

    // Don't place a speed dial at this node.
    vector<int> dp(k + 1, -1);
    dp[0] = 0;

    for (int d = 0; d < ALPHABET; d++)
        if (trie[node].child[d] >= 0)
            for (int i = k; i >= 0; i--)
                if (dp[i] >= 0)
                    for (int c = k - i; c >= 0; c--)
                        maximize(dp[i + c], dp[i] + solve(trie[node].child[d], dist + 1, c));

    for (int i = 0; i <= k; i++)
        maximize(answer, dp[i]);

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    trie.assign(1, trie_node());
    int total_presses = 0;

    for (int i = 0; i < N; i++) {
        string s;
        int m;
        cin >> s >> m;
        total_presses += s.size() * m;
        int current = 0;

        for (char c : s) {
            int index = c - '0';

            if (trie[current].child[index] < 0) {
                trie[current].child[index] = trie.size();
                trie.emplace_back();
            }

            current = trie[current].child[index];
        }

        trie[current].calls += m;
    }

    dfs(0);
    cout << total_presses - solve(0, 0, K) << '\n';
}