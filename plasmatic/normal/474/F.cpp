#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

struct state {
    int gcd, cnt;
};
state comb(state a, state b) {
    state ret{gcd(a.gcd, b.gcd), 0};
    if (a.gcd == ret.gcd) ret.cnt += a.cnt;
    if (b.gcd == ret.gcd) ret.cnt += b.cnt;
    return ret;
}
const int S = 131072;

state seg[S*2+1];

void update(int q, int v) {
    q += S-1;
    seg[q] = {v, 1};
    for (q /= 2; q; q /= 2)
        seg[q] = comb(seg[q*2], seg[q*2+1]);
}
int query(int l, int r) {
    state ret{0, 0};
    for (l += S-1, r += S-1; l <= r; l /= 2, r /= 2) {
        if (l & 1) {
            ret = comb(ret, seg[l]);
            l++;
        }
        if (!(r & 1)) {
            ret = comb(ret, seg[r]);
            r--;
        }
    }
    return ret.cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        update(i, x);
    }
    cin >> Q;
    while (Q--) {
        int l, r; cin >> l >> r;
        cout << (r - l + 1 - query(l, r)) << '\n';
    }
    return 0;
}