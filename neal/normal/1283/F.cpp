#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;
vector<pair<int, int>> edges;
vector<bool> seen;

void add_edge(int a, int b) {
    edges.emplace_back(a, b);
    seen[a] = seen[b] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N - 1);

    for (auto &a : A) {
        cin >> a;
        a--;
    }

    seen.assign(N, false);
    int root = A.front();
    seen[root] = true;
    int last = root;
    int largest = N - 1;

    while (largest >= 0 && seen[largest])
        largest--;

    for (int i = 1; i < N - 1; i++) {
        if (A[i] == largest) {
            add_edge(last, largest);
            last = largest;
        } else if (A[i] == last) {
            add_edge(last, largest);
        } else if (seen[A[i]]) {
            add_edge(last, largest);
            last = A[i];
        } else if (!seen[A[i]]) {
            add_edge(last, A[i]);
            last = A[i];
        }

        while (largest >= 0 && seen[largest])
            largest--;
    }

    add_edge(last, largest);
    cout << root + 1 << '\n';

    for (pair<int, int> &edge : edges)
        cout << edge.first + 1 << ' ' << edge.second + 1 << '\n';
}