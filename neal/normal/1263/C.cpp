#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N;
    cin >> N;
    vector<int> possible = {0};

    for (int i = 1; i <= N; i = N / (N / i) + 1)
        possible.push_back(N / i);

    sort(possible.begin(), possible.end());
    cout << possible.size() << '\n';

    for (int i = 0; i < (int) possible.size(); i++)
        cout << possible[i] << (i < (int) possible.size() - 1 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}