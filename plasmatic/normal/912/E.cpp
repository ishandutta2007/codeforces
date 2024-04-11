// ./e-prime-gift.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using ld = long double;

const __int128 VLIM = 1e18;
const int MN = 16, LIM = 1e7;
int N;
ll K,
   P[MN];

int lptr = 0, rptr = 0;
ll lout[LIM], rout[LIM];

void rec(ll prod, int c, int sz, int &outptr, ll out[LIM]) {
    if (c == sz) {
        out[outptr++] = prod;
        return;
    }
    __int128 pw = 1;
    for (auto i = 0; prod * pw <= VLIM; i++) {
        rec(prod * pw, c+1, sz, outptr, out);
        pw *= P[c];
    }
}

ll cnt(ll lim) {
    ll res = 0;
    int r = rptr-1;
    for (auto i = 0; i < lptr; i++) {
        while (r >= 0 && __int128(lout[i]) * rout[r] > lim) r--;
        res += r+1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 0; i < N; i++)
        cin >> P[i];
    sort(P, P+N);
    cin >> K;

    int lsz = min(6, N), rsz = N-lsz;
    rec(1, 0, lsz, lptr, lout);
    reverse(P, P+N);
    rec(1, 0, rsz, rptr, rout);
    reverse(P, P+N);
    sort(lout, lout+lptr);
    sort(rout, rout+rptr);

    // for (auto i = 0; i < min(lptr, 20); i++)
    //     printf("%lld ", lout[i]);
    // printf("\n");

    ll l = 0, r = 1e18;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (cnt(mid) < K) l = mid;
        else r = mid;
    }
    cout << r << '\n';

    return 0;
}