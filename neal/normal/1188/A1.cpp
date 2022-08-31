#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> degree(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        degree[u]++;
        degree[v]++;
    }

    bool good = true;

    for (int i = 0; i < N; i++)
        if (degree[i] == 2)
            good = false;

    cout << (good ? "YES" : "NO") << '\n';
}