#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    string S;
    cin >> N >> S;
    vector<int> counts(N + 1, 0);
    int64_t sum = 0, answer = 0;
    int run = 0;

    for (auto &ch : S) {
        if (ch == '1') {
            int move = counts[run];
            counts[run] = 0;
            counts[max(run, 1)]++;
            sum += move + max(run, 1);
            run++;
            counts[run] += move;
        } else {
            run = 0;
            counts[0]++;
        }

        answer += sum;
    }

    cout << answer << '\n';
}