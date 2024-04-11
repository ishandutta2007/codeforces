#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    string X, Y;
    cin >> X >> Y;
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    int first_one = -1;

    for (int i = 0; i < (int) Y.size(); i++)
        if (Y[i] == '1') {
            first_one = i;
            break;
        }

    assert(first_one >= 0);
    int count = 0;

    while (X[first_one + count] != '1')
        count++;

    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}