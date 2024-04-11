#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

struct Data {
    int x, y, z;
    Data(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};
vector<Data> res;

void add(int x, int y, int z) {
    a[x] ^= 1;
    a[y] ^= 1;
    a[z] ^= 1;
    res.push_back(Data(z, y, x));
}

void go(int u) {
    if (a[u - 5] == 1 && a[u - 4] == 1 && a[u - 3] == 1) {
        add(u, u - 4, u - 8);
        add(u - 1, u - 3, u - 5);
    } else {
        int pos = 6;
        for (int i = 3; i <= 5; i++) {
            if (a[u - i]) {
                pos = i;
                break;
            }
        }
        add(u, u - pos, u - pos * 2);
        pos = 6;
        for (int i = 3; i <= 5; i++) {
            if (a[u - i]) {
                pos = i;
                break;
            }
        }
        pos--;
        u--;
        add(u, u - pos, u - pos * 2);
    }
}

const int K = 12;

int dp[1 << K];
int nxt[1 << K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 12; i--) {
        if (a[i] == 0) {
            continue;
        }
        if (a[i - 1] == 0) {
            if (a[i - 2] == 0) {
                add(i, i - 3, i - 6);
            } else {
                add(i, i - 2, i - 4);
            }
        } else {
            if (a[i - 2] == 0) {
                go(i);
            } else {
                add(i, i - 1, i - 2);
            }
        }
    }
    n = min(n, 12);
    for (int i = 0; i < (1 << n); i++) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int delta = j - i;
                int k = j + delta;
                if (k >= n) continue;
                int newMask = u ^ (1 << i) ^ (1 << j) ^ (1 << k);
                if (dp[newMask] > dp[u] + 1) {
                    dp[newMask] = dp[u] + 1;
                    q.push(newMask);
                    nxt[newMask] = u;
                }
            }
        }
    }
    int mask = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            mask ^= (1 << (i - 1));
        }
    }
    if (dp[mask] >= 1e8) {
        puts("NO");
    } else {
        while (mask > 0) {
            int foo = mask ^ nxt[mask];
            int a[3];
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((foo >> i) & 1) {
                    foo ^= (1 << i);
                    a[cnt++] = i + 1;
                    if (cnt == 3) {
                        break;
                    }
                }
            }
            add(a[2], a[1], a[0]);
            mask = nxt[mask];
        }
        puts("YES");
        printf("%d\n", (int)res.size());
        for (auto u : res) {
            printf("%d %d %d\n", u.x, u.y, u.z);
        }
    }
    return 0;
}