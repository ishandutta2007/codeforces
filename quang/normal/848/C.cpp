#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int BLOCK_SIZE = 1500;

int n, m;
int a[N];
set<int> posInA[N];
int leftPos[N];

struct BIT {
    long long t[N];

    void add(int x, long long v) {
        if (x == 0) return;
        for (; x < N; x += x & -x) t[x] += v;
    }

    long long get(int x) {
        long long res = 0;
        for (; x; x -= x & -x) res += t[x];
        return res;
    }

    long long get(int l, int r) {
        return get(r) - (l ? get(l - 1) : 0);
    }
} t[N / BLOCK_SIZE + 10];

void update(int u, int sign) {
    int blockId = (u - 1) / BLOCK_SIZE + 1;
    t[blockId].add(leftPos[u], sign * (u - leftPos[u]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (posInA[a[i]].empty()) leftPos[i] = 0;
        else leftPos[i] = *posInA[a[i]].rbegin();
        posInA[a[i]].insert(i);
        update(i, 1);
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x;
            // erase 
            update(p, -1);
            auto it = posInA[a[p]].upper_bound(p);
            if (it != posInA[a[p]].end()) {
                update(*it, -1);
                leftPos[*it] = leftPos[p];
                update(*it, 1);
            }
            posInA[a[p]].erase(p);
            // add
            a[p] = x;
            leftPos[p] = 0;
            it = posInA[x].upper_bound(p);
            if (it != posInA[x].begin()) {
                it--;
                leftPos[p] = *it;
            }
            update(p, 1);
            it = posInA[x].upper_bound(p);
            if (it != posInA[x].end()) {
                update(*it, -1);
                leftPos[*it] = p;
                update(*it, 1);
            }
            posInA[x].insert(p);
        } else {
            int l, r;
            cin >> l >> r;
            long long res = 0;
            int lBlock = (l - 1) / BLOCK_SIZE + 1;
            int rBlock = (r - 1) / BLOCK_SIZE + 1;
            if (lBlock == rBlock) {
                for (int i = l; i <= r; i++) {
                    if (leftPos[i] >= l) res += i - leftPos[i];
                }
            } else {
                for (int blockId = lBlock + 1; blockId < rBlock; blockId++) {
                    res += t[blockId].get(l, n);
                }
                for (int i = l; (i - 1) / BLOCK_SIZE + 1 == lBlock; i++) {
                    if (leftPos[i] >= l) res += i - leftPos[i];
                }
                for (int i = r; (i - 1) / BLOCK_SIZE + 1 == rBlock; i--) {
                    if (leftPos[i] >= l) res += i - leftPos[i];
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}