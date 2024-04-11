#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    vector<int> boys(N), girls(M);

    for (auto &b : boys)
        cin >> b;

    for (auto &g : girls)
        cin >> g;

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    if (boys.back() > girls.front()) {
        cout << -1 << '\n';
        return 0;
    }

    long long total = accumulate(boys.begin(), boys.end(), 0LL) * M;
    total -= (M - 1) * boys.back() + (boys.back() == girls.front() ? boys.back() : boys[N - 2]);
    total += accumulate(girls.begin(), girls.end(), 0LL);
    cout << total << '\n';
}