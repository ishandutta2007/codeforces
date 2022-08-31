#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    size_t first_bracket = S.find_first_of('[');
    size_t first_colon = S.find_first_of(':', first_bracket);
    size_t last_bracket = S.find_last_of(']');
    size_t last_colon = S.find_last_of(':', last_bracket);

    if (first_bracket == string::npos || last_bracket == string::npos ||
        first_colon == string::npos || last_colon == string::npos || first_colon >= last_colon) {
        cout << -1 << '\n';
        return 0;
    }

    int answer = 4;

    for (size_t index = first_colon; index < last_colon; index++)
        if (S[index] == '|')
            answer++;

    cout << answer << '\n';
}