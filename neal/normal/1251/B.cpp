#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N;
    cin >> N;
    vector<string> strings(N);
    bool odd = false;
    int counts[2] = {0, 0};

    for (string &str : strings) {
        cin >> str;
        odd = odd || str.size() % 2 != 0;

        for (char c : str)
            counts[c - '0']++;
    }

    int answer = (odd || counts[0] % 2 == 0) ? N : N - 1;
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}