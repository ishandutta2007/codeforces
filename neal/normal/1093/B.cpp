#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- > 0) {
        string S;
        cin >> S;
        sort(S.begin(), S.end());
        string reversed = S;
        reverse(reversed.begin(), reversed.end());

        if (S == reversed)
            cout << -1 << '\n';
        else
            cout << S << '\n';
    }
}