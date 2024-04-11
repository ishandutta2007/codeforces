#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 1e5 + 5;

int m;
char s[MAXN];
int bdv;
vector<pii> rmq;

pii segtree_get(int v, int vl, int vr, int l, int r) {
    //cerr << v << " " << vl << " " << vr << " " << l << " " << r << endl;
    if (vr <= l || r <= vl) {
        return {100, -1};
    }
    if (l <= vl && vr <= r) {
        return rmq[v];
    }
    int vm = (vl + vr) / 2;
    return min(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
}

bool cmp(int a, int b) {
    return s[a] < s[b];
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &m);
    scanf("%s", s);
    int n = strlen(s);

    bdv = 1;
    while (bdv < n) {
        bdv *= 2;
    }

    rmq.resize(bdv * 2);

    for (int i = 0; i < n; ++i) {
        rmq[i + bdv] = {s[i] - 'a', i};
    }

    for (int i = n; i < bdv; ++i) {
        rmq[i + bdv] = {100, i};
    }

    for (int i = bdv - 1; i > 0; --i) {
        rmq[i] = min(rmq[i * 2], rmq[i * 2 + 1]);
    }

    char maxv = 'a';
    for (int i = 0; i < n - m + 1; ++i) {
        maxv = max(segtree_get(1, 0, bdv, i, i + m).ff, maxv - 'a') + 'a';
    }

    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] < maxv) {
            used[i] = true;
        }
    }

    int prev = -1, last = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == maxv) {
            last = i;
        }
        if (used[i]) {
            prev = i;
        }
        if (i - prev == m) {
            used[last] = 1;
            prev = last;
        }
    }
    
    vector<char> v;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            v.puba(s[i]);
        }
    }

    sort(bend(v));

    for (char c: v) {
        cout << c;
    }
    cout << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}