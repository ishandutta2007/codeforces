#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N;
    cin >> N;
    vector<pair<int, int>> packages(N);

    for (pair<int, int> &pkg : packages)
        cin >> pkg.first >> pkg.second;

    sort(packages.begin(), packages.end());
    int x = 0, y = 0;
    string answer;

    for (pair<int, int> &pkg : packages) {
        if (pkg.first < x || pkg.second < y) {
            cout << "NO" << '\n';
            return;
        }

        while (x < pkg.first) {
            answer += 'R';
            x++;
        }

        while (y < pkg.second) {
            answer += 'U';
            y++;
        }
    }

    cout << "YES" << '\n';
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}