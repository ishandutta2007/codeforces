#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
long long K;

bool possible_x(int best_x, int x, int y) {
    return best_x <= K && x <= K * y - best_x && y <= K * (x + 1);
}

long long solve_x(long long best_x, long long x, long long y) {
    if (best_x > K)
        return K + 1;

    long long min_end = max(x - (K * y - best_x), 1LL);

    if (min_end > x || min_end > K)
        return K + 1;

    if (y <= K * (x - min_end + 1))
        return min_end;

    return K + 1;
}

bool possible_y(int best_y, int x, int y) {
    return best_y <= K && x <= K * y && y <= K * (x + 1) - best_y;
}

long long solve_y(long long best_y, long long x, long long y) {
    if (best_y > K)
        return K + 1;

    long long min_end = max(x - K * y, 1LL);

    if (min_end > x || min_end > K)
        return K + 1;

    if (y <= K * (x - min_end + 1) - best_y)
        return min_end;

    return K + 1;
}

int solve(int best_x, int best_y, int x, int y) {
    long long x_ans = solve_x(best_x, x, y);
    long long y_ans = solve_y(best_y, x, y);
    // cerr << "params: " << best_x << ' ' << best_y << ' ' << x << ' ' << y << endl;
    // cerr << "solve: " << x_ans << ' ' << y_ans << endl;
    assert(x_ans > K || possible_x(best_x, x - x_ans, y));
    assert(y_ans > K || possible_y(best_y, x - y_ans, y));
    return min(x_ans, y_ans);
}

int main() {
    scanf("%d %lld", &N, &K);
    vector<int> X(N), Y(N);

    for (int &x : X)
        scanf("%d", &x);

    for (int &y : Y)
        scanf("%d", &y);

    int best_x = 0, best_y = 0;
    bool possible = true;

    for (int i = 0; i < N; i++) {
        int next_x = solve(best_x, best_y, X[i], Y[i]);
        int next_y = solve(best_y, best_x, Y[i], X[i]);
        best_x = next_x;
        best_y = next_y;
        // cerr << i << ": " << best_x << ' ' << best_y << endl;

        if (best_x > K && best_y > K)
            possible = false;
    }

    puts(possible ? "YES" : "NO");
}