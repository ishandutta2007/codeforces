#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> tree_min;
    vector<int> tree_max;
    
    SegmentTree(int n) {
        tree_min.resize(4 * n);
        tree_max.resize(4 * n);
    }

    int qmin(int le, int ri, int n, int tl, int tr) {
        if (ri < tl || tr < le || tl > tr) return (int)1e8;
        if (le <= tl && tr <= ri) return tree_min[n];
        int mid = (tl + tr) / 2;
        return min(qmin(le, ri, n * 2, tl, mid), qmin(le, ri, n * 2 + 1, mid + 1, tr));
    }

    int qmax(int le, int ri, int n, int tl, int tr) {
        if (ri < tl || tr < le || tl > tr) return 0;
        if (le <= tl && tr <= ri) return tree_max[n];
        int mid = (tl + tr) / 2;
        return max(qmax(le, ri, n * 2, tl, mid), qmax(le, ri, n * 2 + 1, mid + 1, tr));
    }

    void upd(int p, int x, int n, int tl, int tr) {
        if (tl == tr) {
            tree_min[n] = tree_max[n] = x;
            return;
        }
        int mid = (tl + tr) / 2;
        if (p <= mid) upd(p, x, n * 2, tl, mid);
        else upd(p, x, n * 2 + 1, mid + 1, tr);
        tree_min[n] = min(tree_min[n * 2], tree_min[n * 2 + 1]);
        tree_max[n] = max(tree_max[n * 2], tree_max[n * 2 + 1]);   
    }

};

int solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    map<int, int> freqA, freqB;
    for (int i = 0; i < N; i++) {
        freqA[A[i]]++;
        freqB[B[i]]++;
    }

    if (freqA != freqB) {
        cout << "NO\n";
        return 0;
    }

    map<int, deque<int>> pos;
    for (int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }

    SegmentTree seg(N);
    for (int i = 0; i < N; i++) {
        seg.upd(i, A[i], 1, 0, N - 1);
    }    

    bool can = true;
    for (int i = 0; i < N; i++) {
        int p = pos[B[i]].front();
        pos[B[i]].pop_front();
        // cout << i << " " << p << "\n";
        if (seg.qmin(0, p, 1, 0, N - 1) >= B[i]) {
            seg.upd(p, 1e8, 1, 0, N - 1);
            continue;
        }
        can = false;
        break;
        
    }
    if (can) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}