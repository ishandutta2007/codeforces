#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LENGTH_MAX = 1e6 + 5;

int N;
vector<string> sequences;
int valid_count[2 * LENGTH_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    sequences.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> sequences[i];
        int sum = 0, min_sum = LENGTH_MAX;

        for (char c : sequences[i]) {
            sum += c == '(' ? +1 : -1;
            min_sum = min(min_sum, sum);
        }

        if (min_sum >= min(sum, 0))
            valid_count[LENGTH_MAX + sum]++;
    }

    int total = valid_count[LENGTH_MAX] / 2;

    for (int i = 1; i < LENGTH_MAX; i++)
        total += min(valid_count[LENGTH_MAX + i], valid_count[LENGTH_MAX - i]);

    cout << total << '\n';
}