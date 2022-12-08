#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stderr)

const int dd = (int)1e5 + 7;

map<ll, int> M;

bool check(int m) {
    err("check m = %d\n", m);
    int A = m, B = M[1] - m;
    for (auto i : M) {
        err("%d %d\n", A, B);
        if (i.first == 1) continue;
        ll t = i.first;
        int cnt = i.second;
        if (t == (t & -t)) {
            int pr = min(A, cnt);
            B -= min(B, A - pr);
            B += max(0, cnt - A);
            A = pr;
        } else {
            B += cnt;
        }
    }
    return A >= B;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        M[x]++;
    }
    for (ll i = 1; i >= 0; i *= 2)
        M[i] += 0;
    int l = 0, r = M[1] + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m;
    }
    if (r == M[1] + 1) return 0 * puts("-1");
    for (int i = r; i <= M[1]; ++i)
        printf("%d ", i);
    return 0;
}