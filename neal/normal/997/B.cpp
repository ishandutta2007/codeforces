#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;
    long long M = min(N, 50LL);
    unordered_set<int> numbers;

    for (int i = 0; i <= M; i++)
        for (int v = 0; v <= M; v++)
            for (int x = 0; x <= M; x++) {
                int l = M - i - v - x;

                if (l >= 0 && l <= M)
                    numbers.insert(i + 5 * v + 10 * x + 50 * l);
            }

    long long answer = numbers.size() + 49 * (N - M);
    cout << answer << '\n';
    return 0;
}