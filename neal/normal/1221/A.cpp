#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int LOG = 30;
const int GOAL = 11;

void solve_case() {
    int N;
    cin >> N;
    vector<int> freq(LOG, 0);

    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        freq[__builtin_ctz(s)]++;
    }

    for (int i = 0; i < GOAL; i++)
        freq[i + 1] += freq[i] / 2;

    cout << (freq[GOAL] > 0 ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}