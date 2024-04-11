#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    string S;
    cin >> S;

    while (!S.empty() && S.back() == '0')
        S.pop_back();

    while (!S.empty() && S[0] == '0')
        S = S.substr(1);

    cout << count(S.begin(), S.end(), '0') << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}