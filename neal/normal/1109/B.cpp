#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S;

bool is_palindrome(const string &str) {
    int n = str.size();

    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (str[i] != str[j])
            return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    string half = S.substr(0, N / 2);
    bool all_same = true;

    for (char c : half)
        if (c != half.front())
            all_same = false;

    if (all_same) {
        cout << "Impossible" << '\n';
        return 0;
    }

    for (int cut = 1; cut < N; cut++) {
        string candidate = S.substr(cut) + S.substr(0, cut);

        if (candidate != S && is_palindrome(candidate)) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 2 << '\n';
    return 0;
}