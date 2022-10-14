#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint tree[800005], lazy[800005];

lint N, A[200005];

void upd(int n, int tl, int tr, int p, lint x) {
    if (tl == tr) {
        lazy[n] = 0;
        tree[n] = x;
        return;
    }

    if (lazy[n] > 0) {
        if (tree[n * 2] < lazy[n]) lazy[n * 2] = max(lazy[n * 2], lazy[n]);
        if (tree[n * 2] < lazy[n * 2]) tree[n * 2] = lazy[n * 2];
        
        if (tree[n * 2 + 1] < lazy[n]) lazy[n * 2 + 1] = max(lazy[n * 2 + 1], lazy[n]);
        if (tree[n * 2 + 1] < lazy[n * 2 + 1]) tree[n * 2 + 1] = lazy[n * 2 + 1];
        
        lazy[n] = 0;   
    }

    int mid = (tl + tr) / 2;
    if (p <= mid) upd(n * 2, tl, mid, p, x);
    else upd(n * 2 + 1, mid + 1, tr, p, x);

    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
    tree[n] = max(tree[n], lazy[n]);
}

void add(lint x) {
    lazy[1] = max(lazy[1], x);
    tree[1] = max(tree[1], lazy[1]);
}

lint get(int n, int tl, int tr, int p) {
    if (tl == tr) {
        tree[n] = max(tree[n], lazy[n]);
        return tree[n];
    }

    if (lazy[n] > 0) {
        if (tree[n * 2] < lazy[n]) lazy[n * 2] = max(lazy[n * 2], lazy[n]);
        if (tree[n * 2] < lazy[n * 2]) tree[n * 2] = lazy[n * 2];
        
        if (tree[n * 2 + 1] < lazy[n]) lazy[n * 2 + 1] = max(lazy[n * 2 + 1], lazy[n]);
        if (tree[n * 2 + 1] < lazy[n * 2 + 1]) tree[n * 2 + 1] = lazy[n * 2 + 1];
        
        lazy[n] = 0;   
    }

    int mid = (tl + tr) / 2;
    if (p <= mid) return get(n * 2, tl, mid, p);
    else return get(n * 2 + 1, mid + 1, tr, p);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) upd(1, 1, N, i, A[i]);
    int Q; cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            lint p, x; cin >> p >> x;
            upd(1, 1, N, p, x);
        } else {
            lint x; cin >> x;
            add(x);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << get(1, 1, N, i) << " ";

    }
    cout << "\n";

}