#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int tree[800005];
int sz[800005];
int active[800005];

vector<pair<int, int>> A;
void build(int n, int tl, int tr) {
    if (tl == tr) {
        active[n] = 0;
        sz[n] = 0;
        tree[n] = A[tl].second;
        return;
    }
    int mid = (tl + tr) / 2;
    build(n * 2, tl, mid);
    build(n * 2 + 1, mid + 1, tr);
    sz[n] = sz[n * 2] + sz[n * 2 + 1];
}

int que(int n, int tl, int tr, int x, int add = 0) {
    if (tl == tr) {
        return tl;
    }
    int mid = (tl + tr) / 2;
    if (x <= sz[n * 2] + add) {
        return que(n * 2, tl, mid, x, add);
    } else {
        return que(n * 2 + 1, mid + 1, tr, x, add + sz[n * 2]);
    }
}

void upd(int n, int tl, int tr, int x) {
    if (tl == tr) {
        active[n] = 1;
        sz[n] = 1;
        tree[n] = A[tl].second;
        return;
    }
    int mid = (tl + tr) / 2;
    if (x <= mid) {
        upd(n * 2, tl, mid, x);
    } else {
        upd(n * 2 + 1, mid + 1, tr, x);
    }
    sz[n] = sz[n * 2] + sz[n * 2 + 1];
}

void solve() {

    int N; cin >> N;
    A.resize(N + 1);
    vector<int> ori(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i].first;
        A[i].second = -i;
        ori[i] = A[i].first;
    }
    sort(A.begin() + 1, A.end(), greater<pair<int, int>>());
    for (int i = 1; i <= N; i++) A[i].second = -A[i].second;

    int M; cin >> M;
    vector<pair<int, pair<int, int>>> query;
    vector<int> ans(M);

    for (int i = 0; i < M; i++) {
        int K, pos;
        cin >> K >> pos;
        query.push_back({K, {pos, i}});

    }
    sort(query.begin(), query.end());
    build(1, 1, N);
    int cur = 1;

    for (int i = 0; i < M; i++) {
        while (cur <= query[i].first) {
            upd(1, 1, N, A[cur].second);
            cur++;
        }
        ans[query[i].second.second] = que(1, 1, N, query[i].second.first); 
    }

    for (int i = 0; i < M; i++) {
        cout << ori[ans[i]] << "\n";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TESTCASE;
    // cin >> TESTCASE;
    TESTCASE = 1;
    while (TESTCASE--) {
        solve();
    }
}