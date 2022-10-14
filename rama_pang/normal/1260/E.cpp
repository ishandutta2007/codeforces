#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;


pair<lint, lint> tree[1000005];
vector<lint> A;
void build(int n, int tl, int tr) {
    if (tl == tr) {
        tree[n] = {A[tl], tl};
        return;
    }
    int mid = (tl + tr) / 2;
    build(n * 2, tl, mid);
    build(n * 2 + 1, mid + 1, tr);
    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

void upd(int n, int tl, int tr, int x) {
    if (tl == tr) {
        tree[n] = {1e15, -1};
        return;
    }
    int mid = (tl + tr) / 2;
    if (x <= mid) upd(n * 2, tl, mid, x);
    else upd(n * 2 + 1, mid + 1, tr, x);

    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

pair<lint, lint> que(int n, int tl, int tr, int le, int ri) {
    if (ri < tl || tr < le || tl > tr) return {1e15, -1};
    if (le <= tl && tr <= ri) return tree[n];
    int mid = (tl + tr) / 2;
    return min(que(n * 2, tl, mid, le, ri), que(n * 2 + 1, mid + 1, tr, le, ri));
}

void solve() {
    lint N; cin >> N;
    lint me = -1;
    A.resize(N);
    for (lint i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) if (A[i] == -1) me = i;
    build(1, 0, N - 1);


    lint round = log2(N);
    if (me >= N - 1) {
        cout << 0 << "\n";
        return;
    }

    if (me >= (N / 2) - 1) {
        cout << A[N - 1] << "\n";
        return;
    }
    lint ans = 0;
    for (int k = 0; k <= round; k++) {
        if (me >= (N / (1 << k)) - 1) {
            break;
        } else {
            pair<lint, lint> tmp = que(1, 0, N - 1, (N / (1 << k)) - 1, N - 1);
            ans += tmp.first;
            upd(1, 0, N - 1, tmp.second);
        }
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tc = 1;

    #ifdef TESTCASE
    cin >> tc;
    #endif
    
    while (tc--) {
        solve();
    }
}