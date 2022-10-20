#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, q;
int a[N];
vector<int> b[N];
int pos = -1;

struct BIT {
    int t[N];

    void add(int x, int v) {
        while (x < N) {
            t[x] += v;
            x += (x & -x);
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x-= (x & -x);
        }
        return res;
    }
} t;

int nxt[N];


int res[N];
int getNext(int u) {
    if (res[u] == 0) {
        return u;
    }
    return nxt[u] = getNext(nxt[u]);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] == 0) {
            pos = i;
        } else {
            b[a[i]].push_back(i);
            t.add(i, 1);
        }
        nxt[i] = i + 1;
    }
    for (int i = q; i > 0; i--) {
        if (b[i].empty()) {
            if (i != q) {
                continue;
            }
            if (pos == -1) {
                printf("NO\n");
                return 0;
            }
            int x = pos;
            res[x] = i;
        } else {
            int x = b[i][0], y = b[i].back();
            for (int u : b[i]) {
                t.add(u, -1);
            }
            if (t.get(y) - t.get(x - 1) != 0) {
                printf("NO\n");
                return 0;
            }
            for (int j = x; j <= y; j = getNext(j)) {
                if (res[j] == 0) {
                    res[j] = i;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (res[i] == 0) {
            res[i] = 1;
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}