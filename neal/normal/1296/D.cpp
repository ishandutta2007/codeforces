#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, A, B, K;
    cin >> N >> A >> B >> K;
    vector<long long> uses(N, 0);

    for (int i = 0; i < N; i++) {
        long long health;
        cin >> health;
        long long remainder = health % (A + B);

        if (remainder == 0)
            remainder = A + B;

        if (remainder <= A) {
            uses[i] = 0;
            continue;
        }

        long long need = (remainder - 1) / A;
        uses[i] = need;
    }

    sort(uses.begin(), uses.end());
    int answer = 0;

    while (answer < N && uses[answer] <= K) {
        K -= uses[answer];
        answer++;
    }

    cout << answer << '\n';
}