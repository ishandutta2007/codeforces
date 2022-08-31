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
            if (S[i] == '<')
                best = min(best, N - 1 - i);
            else
                best = min(best, i);

        cout << best << '\n';
    }
}