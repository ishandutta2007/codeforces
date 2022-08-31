#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    string A;
    cin >> A;
    string even, odd, answer;

    for (char c : A)
        if ((c - '0') % 2 == 0)
            even += c;
        else
            odd += c;

    answer.resize(A.size());
    merge(even.begin(), even.end(), odd.begin(), odd.end(), answer.begin());
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}