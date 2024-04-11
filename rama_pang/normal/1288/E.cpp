#include <bits/stdc++.h>
using namespace std;
using lint = long long;

/*
Reduce the problem to: count distinc numbers in range (l, r).

5 4 3 2 1 3 5 1 4

Li, Ri


*/

const int MAXN = 1000005;
int tree[MAXN];
void update(int pos, int x) {
    if (pos == 0) {
        return;
    }
    for (int i = pos; i < MAXN; i += (i & -i)) {
        tree[i] += x;
    }
}
int bit_query(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= (i & -i)) {
        res += tree[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> calls(N + M);
    for (int i = 0; i < N; i++) {
        calls[i] = N - i - 1;
    }
    for (int i = N; i < N + M; i++) {
        cin >> calls[i];
        calls[i]--;
    }    
    vector<pair<int, int>> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i].first = i;
    }
    for (int i = N; i < N + M; i++) {
        ans[calls[i]].first = 0;
    }
    
    vector<vector<int>> freq(N);
    for (int i = 0; i < N + M; i++) {
        freq[calls[i]].emplace_back(i);
    }

    vector<pair<pair<int, int>, int>> query;
    for (int i = 0; i < N; i++) {
        freq[i].push_back(N + M);
        for (int j = 0; j + 1 < freq[i].size(); j++) {
            query.push_back({{freq[i][j] + 1, freq[i][j + 1] - 1}, i});
        }
    }
    int INF = 1e9;
    for (int i = 0; i < N + M; i++) {
        query.push_back({{i, i}, -calls[i] - 1});
    }

    sort(begin(query), end(query), [&](auto a, auto b) {
        return a.first.second < b.first.second || (a.first.second == b.first.second && a.second < b.second);
    });
    vector<int> last(N, -1);
    for (auto &q : query) {
        if (q.second < 0) { // add
            update(q.first.first + 1, 1);
            update(last[- q.second - 1] + 1, -1);
            last[- q.second - 1] = q.first.first;
        } else { // query
            if (q.first.first > q.first.second) continue;
            ans[q.second].second = max(ans[q.second].second, bit_query(q.first.second + 1) - bit_query(q.first.first));
        }
    }

    for (auto &i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

}