#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int N;
vector<long long> X;
vector<vector<int>> adj;
long long answer;

void dfs(int node, int parent, const map<long long, int> &freq) {
    map<long long, int> my_freq;
    my_freq[X[node]] = 1;

    for (auto &p : freq)
        my_freq[__gcd(X[node], p.first)] += p.second;

    for (auto &p : my_freq)
        answer += p.first * p.second;

    answer %= MOD;

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dfs(neighbor, node, my_freq);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    X.resize(N);
    adj.assign(N, {});

    for (auto &x : X)
        cin >> x;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    answer = 0;
    dfs(0, -1, {});
    cout << answer % MOD << '\n';
}