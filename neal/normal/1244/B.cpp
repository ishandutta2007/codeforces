#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0) {
        int N;
        string S;
        cin >> N >> S;
        int best = N;

        for (int i = 0; i < N; i++)
            if (S[i] == '1')
                best = max(best, 2 * max(i + 1, N - i));

        cout << best << '\n';
    }
}