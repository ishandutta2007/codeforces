#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET = 26;

bool adj[ALPHABET][ALPHABET];
vector<bool> visited;

void dfs(int c) {
    if (visited[c])
        return;

    cout << (char) ('a' + c);
    visited[c] = true;

    for (int i = 0; i < ALPHABET; i++)
        if (adj[c][i])
            dfs(i);
}

void run_case() {
    memset(adj, false, sizeof(adj));
    string S;
    cin >> S;
    int N = S.size();

    for (int i = 0; i < N - 1; i++) {
        adj[S[i] - 'a'][S[i + 1] - 'a'] = true;
        adj[S[i + 1] - 'a'][S[i] - 'a'] = true;
    }

    vector<int> degree(ALPHABET, 0);

    for (int c = 0; c < ALPHABET; c++) {
        for (int i = 0; i < ALPHABET; i++)
            degree[c] += adj[c][i];

        if (degree[c] > 2) {
            cout << "NO" << '\n';
            return;
        }
    }

    if (count(degree.begin(), degree.end(), 2) > 0 && count(degree.begin(), degree.end(), 1) == 0) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    visited.assign(ALPHABET, false);

    for (int c = 0; c < ALPHABET; c++)
        if (degree[c] == 1) {
            dfs(c);
            break;
        }

    for (int c = 0; c < ALPHABET; c++)
        if (!visited[c])
            cout << (char) ('a' + c);

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}