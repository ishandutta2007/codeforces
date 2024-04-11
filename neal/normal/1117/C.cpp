#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

long long N, X, Y;
string S;

bool possible(long long days) {
    long long x = X, y = Y;

    for (int i = 0; i < N; i++) {
        long long today = days / N + (i < days % N ? 1 : 0);

        if (S[i] == 'U')
            y -= today;
        else if (S[i] == 'D')
            y += today;
        else if (S[i] == 'L')
            x += today;
        else if (S[i] == 'R')
            x -= today;
        else
            assert(false);
    }

    return abs(x) + abs(y) <= days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    X = x2 - x1;
    Y = y2 - y1;
    cin >> N >> S;

    long long low = 0, high = LL_INF;

    while (low < high) {
        long long mid = (low + high) / 2;

        if (possible(mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << (low < LL_INF / 2 ? low : -1) << '\n';
}