#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
 
using namespace std;

#define TASK ""

int solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (TASK == "input") {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (TASK != "") {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    return solve();
}

const int dd = (int)1e5 + 7;

ll A[dd], p[dd], r[dd], cnt = 0;

int get(int a) { return a == p[a] ? a : a = get(p[a]); }

void merge(int a, int b) {
    if ((a = get(a)) == (b = get(b))) {
        return;
    }
    --cnt;
    if (r[a] < r[b]) {
        swap(a, b);
    }
    p[b] = a;
    if (r[a] == r[b]) {
        ++r[a];
    }
}

int solve() {
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < n; ++i) {
        p[i] = i, r[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] > l) {
            ++cnt;
        }
        if (i && A[i] > l && A[i - 1] > l) {
            merge(i, i - 1);
        }
    }
    while (m--) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << cnt << "\n";
        } else {
            int x, d;
            cin >> x >> d;
            --x;
            if (A[x] <= l && A[x] + d > l) {
                ++cnt;
                if (x && A[x - 1] > l) {
                    merge(x, x - 1);
                }
                if (x < n - 1 && A[x + 1] > l) {
                    merge(x, x + 1);
                }
            }
            A[x] += d;
        }
    }
    return 0;
}