#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;


constexpr int BIT = 19;
constexpr int INF = (1 << (BIT + 1));
constexpr int SIGMA = 2;

struct Trie {
    Trie* son[SIGMA];
    Trie() {
        son[0] = son[1] = nullptr;
    }
};


void insert(Trie* node, int val, int bit) {
    if (bit == -1) {
        return;
    }

    int b = ((val & (1 << bit)) > 0);
    if (node->son[b] == nullptr) {
        node->son[b] = new Trie();
    }

    insert(node->son[b], val, bit - 1);
}

int dfs_max(Trie* node, int val, int bit) {
    if (bit == -1) return 0;

    int b = ((val & (1 << bit)) > 0);
    if (node->son[b ^ 1] == nullptr) {
        return dfs_max(node->son[b], val, bit - 1);
    } else {
        return dfs_max(node->son[b ^ 1], val, bit - 1) + (1 << bit);
    }
}

int dfs_min(Trie* node, int val, int bit) {
    if (bit == -1) return 0;

    int b = ((val & (1 << bit)) > 0);
    if (node->son[b] == nullptr) {
        return dfs_min(node->son[b ^ 1], val, bit - 1) + (1 << bit);
    } else {
        return dfs_min(node->son[b], val, bit - 1);
    }
}

int best[BIT + 1][1 << BIT];

void dfs(Trie* node, int bit) {
    if (node == nullptr) return;

    if (node->son[0] != nullptr && node->son[1] != nullptr) {
        for (int mask = 0; mask < (2 << bit); mask++) {
            int& curr = best[bit + 1][mask];

            int b = ((mask & (1 << bit)) > 0);
            curr = min(curr, dfs_min(node->son[b ^ 1], mask, bit - 1) -
                             dfs_max(node->son[b], mask, bit - 1) + (1 << bit));
        }
    }

    for (int i = 0; i < 2; i++) {
        dfs(node->son[i], bit - 1);
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    Trie* root = new Trie();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x, k - 1);
    }

    for (int i = 1; i <= k; i++) {
        for (int mask = 0; mask < (1 << i); mask++) {
            best[i][mask] = INF;
        }
    }

    dfs(root, k - 1);

    for (int mask = 0; mask < (1 << k); mask++) {
        int curr = INF;
        for (int bit = 1; bit <= k; bit++) {
            curr = min(curr, best[bit][mask & ((1 << bit) - 1)]);
        }
        cout << curr << " ";
    }

    return 0;
}