#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct node {
    int val, l, r;
};

string s;
int cur = 0;
vector<node> tree;

int parse() {
    if (s[cur] >= '0' && s[cur] <= '9') {
        tree.push_back({s[cur] - '0', -1, -1});
        cur++;
        return (int) tree.size() - 1;
    }
    // (
    cur++;
    int l = parse();
    // ?
    cur++;
    int r = parse();
    // )
    cur++;
    tree.push_back({0, l, r});
    return (int) tree.size() - 1;
}

vector<vector<int>> dpMin;
vector<vector<int>> dpMax;
bool usePlus;

int mx;

void calc(int x) {
    if (tree[x].l == -1) {
        // leaf;
        dpMax[x][0] = dpMin[x][0] = tree[x].val;
        return;
    }
    int l = tree[x].l;
    int r = tree[x].r;
    calc(l);
    calc(r);
    for (int i = 0; i <= mx; i++) {
        if (dpMax[l][i] == INT_MIN) continue;
        for (int j = 0; i + j <= mx; j++) {
            if (dpMax[r][j] == INT_MIN) continue;
            for (int t = 0; t < 2; t++) {
                int k = i + j;
                if (usePlus && t == 0) k++;
                if (!usePlus && t == 1) k++;
                if (k > mx) continue;
                if (t == 0) {
                    // +
                    dpMax[x][k] = max(dpMax[x][k], dpMax[l][i] +
                                                   dpMax[r][j]);
                    dpMin[x][k] = min(dpMin[x][k], dpMin[l][i] +
                                                   dpMin[r][j]);
                } else {
                    // -
                    dpMax[x][k] = max(dpMax[x][k], dpMax[l][i] -
                                                   dpMin[r][j]);
                    dpMin[x][k] = min(dpMin[x][k], dpMin[l][i] -
                                                   dpMax[r][j]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> s;
    int p, m;
    cin >> p >> m;
    int root = parse();

    usePlus = p < m;
    mx = min(p, m);
    dpMin.assign(tree.size(), vector<int>(mx + 1, INT_MAX));
    dpMax.assign(tree.size(), vector<int>(mx + 1, INT_MIN));
    calc(root);
    cout << dpMax[root][mx];

    return 0;
}