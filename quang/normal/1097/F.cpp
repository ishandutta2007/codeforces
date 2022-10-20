#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int SZ = 7010;

int n, q;
bitset<SZ> a[N];
bool mobious[SZ];
char res[N * 10];
vector<int> divs[SZ];
bitset<SZ> mask[SZ];

void add(int id, int v) {
    a[id].reset();
    for (int u : divs[v]) {
        a[id][u] = a[id][u] ^ 1;
    }
}

int getRes(int id, int v) {
    bitset<SZ> foo = a[id] & mask[v];
    return foo.count() % 2;
}

int main() {
    mobious[1] = 1;
    for (int i = 1; i < SZ; i++) {
        for (int j = i + i; j < SZ; j += i) {
            mobious[j] ^= mobious[i];
        }
        for (int j = i; j < SZ; j += i) {
            divs[j].push_back(i);
        }
    }

    for (int i = 1; i < SZ; i++) {
        for (int j = 1; i * j < SZ; j++) {
            if (mobious[j]) {
                mask[i].set(i * j);
            }
        }
    }
    scanf("%d %d", &n, &q);
    int cnt = 0;
    while (q--) {
        int op, x, y, z, v;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d", &x, &v);
            add(x, v);
        }
        if (op == 2) {
            scanf("%d %d %d", &x, &y, &z);
            a[x] = (a[y] ^ a[z]);
        }
        if (op == 3) {
            scanf("%d %d %d", &x, &y, &z);
            a[x] = (a[y] & a[z]);
        }
        if (op == 4) {
            scanf("%d %d", &x, &v);
            res[++cnt] = ('0' + getRes(x, v));
        }

    }
    printf("%s\n", res + 1);
    return 0;
}