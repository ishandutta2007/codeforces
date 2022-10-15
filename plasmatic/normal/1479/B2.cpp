// ./b2-painting-the-array-ii.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

/*
 * dp[i][j] -> answer with prefix 1..i, end of pre==j
 *
 * Initialization: dp[1][N+1] = 1
 * dp[i][j] + (A[i] != A[i-1]) -> dp[i+1][j] 
 * - Swap sequence
 * dp[i][j] + (A[i] != j) -> dp[i][A[i]]
 *   - min({query(1, A[i]-1)+1, query(A[i]+1, N+1)+1, query(A[i], A[i])})
 */

const int MN = 1e5 + 10;
int N,
    A[MN];

#define MID int mid = (l + r) / 2, lhs = i+1, rhs = i + (mid-l+1)*2
int seg[MN*2], lazy[MN*2];
void push(int i, int l, int r) {
    if (lazy[i]) {
        seg[i] += lazy[i];
        if (l != r) {
            MID;
            lazy[lhs] += lazy[i];
            lazy[rhs] += lazy[i];
        }
        lazy[i] = 0;
    }
}
int update(int ql, int qr, int qv, int i=1, int l=1, int r=N+1) {
    push(i, l, r);
    if (ql > r || qr < l) return seg[i];
    if (l >= ql && r <= qr) {
        lazy[i] = qv;
        push(i, l, r);
        return seg[i];
    }
    MID;
    return seg[i] = min(update(ql, qr, qv, lhs, l, mid), update(ql, qr, qv, rhs, mid+1, r));
}
int updatePoint(int q, int v, int i=1, int l=1, int r=N+1) {
    push(i, l, r);
    if (q > r || q < l) return seg[i];
    if (l == q && r == q) return seg[i] = min(seg[i], v);
    MID;
    return seg[i] = min(updatePoint(q, v, lhs, l, mid), updatePoint(q, v, rhs, mid+1, r));
}
int query(int ql, int qr, int i=1, int l=1, int r=N+1) {
    if (ql > r || qr < l) return INF;
    push(i, l, r);
    if (l >= ql && r <= qr) return seg[i];
    MID;
    return min(query(ql, qr, lhs, l, mid), query(ql, qr, rhs, mid+1, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    memset(seg, 0x3f, sizeof seg);
    updatePoint(N+1, 1);
    for (int i = 2; i <= N; i++) {
        int q = min({query(1, A[i]-1)+1, query(A[i], A[i]), query(A[i]+1, N+1)+1});
        // don't swap
        update(1, N+1, A[i] != A[i-1]);
        updatePoint(A[i-1], q);

        // printf("i=%d dp=", i);
        // for (int j=1;j<=N+1;j++) {
        //     printf("%d ", query(j,j));
        // }
        // printf("\n");
    }

    cout << query(1, N+1) << '\n';

    return 0;
}