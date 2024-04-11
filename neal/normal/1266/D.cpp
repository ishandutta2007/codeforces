#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N, M;
vector<long long> balance;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    balance.assign(N, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        long long d;
        cin >> u >> v >> d;
        u--; v--;
        balance[u] -= d;
        balance[v] += d;
    }

    vector<int> negative, positive;

    for (int i = 0; i < N; i++)
        if (balance[i] < 0)
            negative.push_back(i);
        else if (balance[i] > 0)
            positive.push_back(i);

    vector<tuple<int, int, long long>> ops;

    while (!negative.empty() && !positive.empty()) {
        int neg = negative.back();
        int pos = positive.back();
        long long move = min(abs(balance[neg]), balance[pos]);
        ops.emplace_back(neg, pos, move);
        balance[neg] += move;
        balance[pos] -= move;

        if (balance[neg] == 0)
            negative.pop_back();

        if (balance[pos] == 0)
            positive.pop_back();
    }

    assert(negative.empty() && positive.empty());
    cout << ops.size() << '\n';

    for (auto &op : ops)
        cout << get<0>(op) + 1 << ' ' << get<1>(op) + 1 << ' ' << get<2>(op) << '\n';
}