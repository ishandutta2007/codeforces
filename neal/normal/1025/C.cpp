#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;
    N = str.size();
    str += str;
    int best = 0;

    for (int i = 0, j = 0; i < N; i = j) {
        j = max(j, i + 1);

        while (j < 2 * N && str[j] != str[j - 1])
            j++;

        best = max(best, min(j - i, N));
    }

    cout << best << '\n';
    return 0;
}