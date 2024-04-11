/**
 * If we fix k and say that all first subset elements must have value less
 * than k, then the minimum cost can be found in O(n).
 * 
 * Maintain costPrefix for elements greater than k, and costSuffix for elements
 * not greater than k. Observe that for an index i, the cost is costPrefix[i] +
 * costSuffix[i], as they do not overlap (current index can only contribute
 * to either prefix or suffix).
 * 
 * We can simply iterate through costPrefix and costSuffix.
 * 
 * What if we want to find costPrefix and costSuffix for fixed element k + 1?
 * 
 * First we find element k + 1, and move its cost from costSuffix to costPrefix.
 * So we do a range update over prefixes for costSuffix, and range update over
 * suffixes for costPrefix. Then we can RMQ to find least cost.
 * 
 * Range updates and queries can be implemented with a segment tree.
 * 
**/


#include <bits/stdc++.h>
using namespace std;
using lint = long long;


const int SZ = 200005;

lint tree[4 * SZ]; // costPrefix + costSuffix
lint lazy[4 * SZ]; // lazy

lint initialCost[SZ];

void build(int n, int tl, int tr) {
    if (tl == tr) {
        tree[n] = initialCost[tl];
        return;
    }
    int mid = (tl + tr) / 2;
    build(n * 2, tl, mid);
    build(n * 2 + 1, mid + 1, tr);
    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

void push(int n) {
    tree[n * 2] += lazy[n];
    lazy[n * 2] += lazy[n];
    tree[n * 2 + 1] += lazy[n];
    lazy[n * 2 + 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl || tl > tr) return;
    if (l <= tl && tr <= r) {
        tree[n] += x;
        lazy[n] += x;
        return;
    }
    push(n);
    int mid = (tl + tr) / 2;
    update(n * 2, tl, mid, l, r, x);
    update(n * 2 + 1, mid + 1, tr, l, r, x);
    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

lint query(int n, int tl, int tr, int l, int r) {
    if (tr < l || r < tl || tl > tr) return 1e18;
    if (l <= tl && tr <= r) return tree[n];
    push(n);
    int mid = (tl + tr) / 2;
    return min( query(n * 2, tl, mid, l, r), query(n * 2 + 1, mid + 1, tr, l, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> p(n), a(n), where(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        where[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    initialCost[0] = a[0];
    for (int i = 1; i < n; i++) {
        initialCost[i] += initialCost[i - 1];
        initialCost[i] += a[i];
    }

    build(1, 0, n - 1);
    lint ans = query(1, 0, n - 1, 0, n - 2);

    for (int i = 0; i < n; i++) {
        update(1, 0, n - 1, 0, where[i] - 1, a[where[i]]); // increase for costSuffix
        update(1, 0, n - 1, where[i], n - 1, -a[where[i]]); // decrease for costPrefix
        ans = min(ans, query(1, 0, n - 1, 0, n - 2));
    }

    cout << ans << '\n';
    return 0;
}