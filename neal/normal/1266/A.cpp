#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    string Y;
    cin >> Y;
    bool possible = true;
    bool has_zero = false;

    for (char &c : Y)
        if (c == '0') {
            swap(c, Y.back());
            Y.pop_back();
            has_zero = true;
            break;
        }

    if (!has_zero)
        possible = false;

    bool has_even = false;

    for (char c : Y)
        if (c % 2 == 0)
            has_even = true;

    if (!has_even)
        possible = false;

    int sum = 0;

    for (char c : Y)
        sum += c - '0';

    if (sum % 3 != 0)
        possible = false;

    cout << (possible ? "red" : "cyan") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}