#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 123;
const int INF = (int) 1e9 + 123;

int n, q;
char a[N];

struct Node {
    int dp[5][5];
    
    Node() {
        for (int i = 0; i < 5; i++) {
            for (int j = i; j < 5; j++) {
                dp[i][j] = INF;
                if (i == j) {
                    dp[i][j] = 0;
                }
            }
        }
    }
    
    void init(int v) {
        if (v == 2) {
            dp[0][0] = 1;
            dp[0][1] = 0;
        } else if (v == 0) {
            dp[1][1] = 1;
            dp[1][2] = 0;
        } else if (v == 1) {
            dp[2][2] = 1;
            dp[2][3] = 0;
        } else if (v == 7) {
            dp[3][3] = 1;
            dp[3][4] = 0;
        } else if (v == 6) {
            dp[3][3] = 1;
            dp[4][4] = 1;
        }
    }
};

Node operator+(const Node &a, const Node &b) {
    Node ans;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ans.dp[i][j] = INF;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            for (int k = i; k <= j; k++) {
                ans.dp[i][j] = min(ans.dp[i][j], a.dp[i][k] + b.dp[k][j]);
            }
        }
    }
    
    return ans;
}

Node neutral;
Node tree[4 * N];

Node get(int i, int tl, int tr, int l, int r) {
    if (tl >= tr || tl >= r || tr <= l) {
        return neutral;
    }
    
    if (l <= tl && tr <= r) {
        return tree[i];
    }
    
    int tm = (tl + tr) / 2;
    return get(2 * i + 1, tl, tm, l, r) + get(2 * i + 2, tm, tr, l, r);
}

void build(int i, int tl, int tr) {
    if (tl >= tr) {
        return;
    }
    
    if (tl == tr - 1) {
        tree[i].init(a[tl] - '0');
        return;
    }
    
    int tm = (tl + tr) / 2;
    build(2 * i + 1, tl, tm);
    build(2 * i + 2, tm, tr);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

void run() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n);
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = get(0, 0, n, l - 1, r).dp[0][4];
        if (ans == INF) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}