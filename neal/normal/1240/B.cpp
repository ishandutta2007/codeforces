#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;
vector<int> first, last;

void solve_case() {
    cin >> N;
    A.resize(N);

    for (int &a : A) {
        cin >> a;
        a--;
    }

    first.assign(N, -1);
    last.assign(N, -1);
    vector<int> sorted;

    for (int i = 0; i < N; i++) {
        if (first[A[i]] < 0)
            first[A[i]] = i;

        last[A[i]] = i;
        sorted.push_back(A[i]);
    }

    sort(sorted.begin(), sorted.end());
    sorted.resize(unique(sorted.begin(), sorted.end()) - sorted.begin());
    int S = sorted.size();
    int best = S - 1;

    for (int a = 0, b = 0; a < S; a++) {
        b = max(b, a + 1);

        while (b < S && first[sorted[b]] > last[sorted[b - 1]])
            b++;

        best = min(best, S - (b - a));
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}