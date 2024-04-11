#include <bits/stdc++.h>
using namespace std;
pair<int, int> tree[4000005];
int add[4000005];
int lazy[4000005];

void upd(int n, int tl, int tr, int p, pair<int, int> x) {
    if (tl == tr) {
        tree[n] = x;
        return;
    }
    int mid = (tl + tr) / 2;
    if (p <= mid) upd(n * 2, tl, mid, p, x);
    else upd(n * 2 + 1, mid + 1, tr, p, x);
    pair<int, int> val;
    if (tree[n * 2].first >= tree[n * 2 + 1].second) {
        val.first = tree[n * 2].first - tree[n * 2 + 1].second + tree[n * 2 + 1].first;
        val.second = tree[n * 2].second;
    } else {
        val.first = tree[n * 2 + 1].first;
        val.second = tree[n * 2 + 1].second - tree[n * 2].first + tree[n * 2].second;
    }
    tree[n] = val;
}

inline void lazydown(int n) {
    if (lazy[n] == 0) return;
    add[n * 2] += lazy[n];
    add[n * 2 + 1] += lazy[n];
    lazy[n * 2] += lazy[n];
    lazy[n * 2 + 1] += lazy[n];
    lazy[n] = 0;
}

void rng(int n, int tl, int tr, int le, int ri, int x) {
    if (tr < le || ri < tl || tl > tr) return;
    if (le <= tl && tr <= ri) {
        lazy[n] += x;
        add[n] += x;
        return;
    }

    lazydown(n);
    int mid = (tl + tr) / 2;
    rng(n * 2, tl, mid, le, ri, x);
    rng(n * 2 + 1, mid + 1, tr, le, ri, x);
    add[n] = max(add[n * 2], add[n * 2 + 1]);
}


int main() {
    int N; cin >> N;
    string s; cin >> s;
    int cur = 0;
    string S(N + 10, '_');

    for (int i = 0; i < N; i++) {
        if (s[i] == 'L') {
            cur--;
            if (cur < 0) cur = 0;
        } else if (s[i] == 'R') {
            cur++;
        } else if (s[i] == '(') {
            upd(1, 0, N - 1, cur, {1, 0});


            if (S[cur] == ')') rng(1, 0, N - 1, cur, N - 1, 1);
            if (S[cur] == '(') rng(1, 0, N - 1, cur, N - 1, -1);
            rng(1, 0, N - 1, cur, N - 1, 1);

            S[cur] = '(';
        } else if (s[i] == ')') {
            upd(1, 0, N - 1, cur, {0, 1});

            if (S[cur] == ')') rng(1, 0, N - 1, cur, N - 1, 1);
            if (S[cur] == '(') rng(1, 0, N - 1, cur, N - 1, -1);
            rng(1, 0, N - 1, cur, N - 1, -1);

            S[cur] = ')';
        } else {
            upd(1, 0, N - 1, cur, {0, 0});
            
            if (S[cur] == ')') rng(1, 0, N - 1, cur, N - 1, 1);
            if (S[cur] == '(') rng(1, 0, N - 1, cur, N - 1, -1);

            S[cur] = '_';

        }

        if (tree[1] == make_pair(0, 0)) {
            cout << add[1] << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << "\n";
    
}