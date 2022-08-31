#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve_case() {
    string S;
    cin >> S;
    int n = S.size();
    set<char> odd;

    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && S[i] == S[j])
            j++;

        if ((j - i) % 2 != 0)
            odd.insert(S[i]);
    }

    cout << string(odd.begin(), odd.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}