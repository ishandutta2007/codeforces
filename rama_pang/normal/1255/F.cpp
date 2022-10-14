#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N;
int query_count = 0;
map<tuple<int, int, int>, int> memo_c;
map<tuple<int, int, int>, lint> memo_a;

int clockwise(int i, int j, int k) {
    if (memo_c.find(tuple<int, int, int>(i, j, k)) != memo_c.end()) {
        return memo_c[tuple<int, int, int>(i, j, k)];
    }
    query_count++;
    int res, t = 2;
    cout << t << " " << i << " " << j << " " << k << endl;
    cin >> res;

    memo_c[tuple<int, int, int>(i, j, k)] = res;
    memo_c[tuple<int, int, int>(j, k, i)] = res;
    memo_c[tuple<int, int, int>(k, i, j)] = res;
    
    memo_c[tuple<int, int, int>(k, j, i)] = -res;
    memo_c[tuple<int, int, int>(j, i, k)] = -res;
    memo_c[tuple<int, int, int>(i, k, j)] = -res;

    return res;
}

lint area(int i, int j, int k) {
    if (memo_a.find(tuple<int, int, int>(i, j, k)) != memo_a.end()) {
        return memo_a[tuple<int, int, int>(i, j, k)];
    }
    query_count++;
    lint res, t = 1;
    cout << t << " " << i << " " << j << " " << k << endl;
    cin >> res;

    memo_a[tuple<int, int, int>(i, j, k)] = res;
    memo_a[tuple<int, int, int>(j, k, i)] = res;
    memo_a[tuple<int, int, int>(k, i, j)] = res;
    
    memo_a[tuple<int, int, int>(k, j, i)] = res;
    memo_a[tuple<int, int, int>(j, i, k)] = res;
    memo_a[tuple<int, int, int>(i, k, j)] = res;

    return res;
}

vector<int> solve(int d1, int d2, vector<int> A) { // d1, d2, and A is clokcwise, 
    deque<int> res;
    if (A.empty()) {
        return vector<int>(1, d2);
    }

    int top = A.front();
    vector<int> vis(N + 1, 0);
    for (auto i : A) {
        if (area(d1, d2, i) > area(d1, d2, top)) {
            top = i;
        }
    }
    vis[top] = 1;
    res.emplace_back(top);

    while (res.size() < A.size()) {
        int id = -1;
        for (auto i : A) {
            if (vis[i]) continue;
            if (id == -1) id = i;
            if (area(d1, d2, i) > area(d1, d2, id)) {
                id = i;
            }
        }
        vis[id] = 1;
        if (clockwise(d2, top, id) == 1) {
            res.emplace_back(id);
        } else {
            res.emplace_front(id);
        }
    }

    res.emplace_front(d2);
    return vector<int>(res.begin(), res.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> L, R;
    for (int i = 3; i <= N; i++) {
        if (clockwise(1, 2, i) == 1) {
            L.emplace_back(i);
        } else {
            R.emplace_back(i);
        }
    }

    vector<int> ans, ansL, ansR;
    // for (auto i : R) cout << i << " ";

    ansL = solve(1, 2, L);
    ansR = solve(2, 1, R);

    for (auto i : ansR) {
        ans.emplace_back(i);
    }
    for (auto i : ansL) {
        ans.emplace_back(i);
    }
    
    cout << 0;
    for (auto i : ans) {
        cout << " " << i;
    }
    cout << "\n";

    // cout << "QUERIES: " << query_count << "\n";

    return 0;

}