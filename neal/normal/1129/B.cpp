#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int LEN_MAX = 2000;
const int A_MAX = 1e6;

int K;

long long alice(vector<int> sequence) {
    long long res = 0, cur = 0;
    int n = sequence.size(), k = -1;

    for (int i = 0; i < n; i++) {
        cur += sequence[i];

        if (cur < 0) {
            cur = 0;
            k = i;
        }

        res = max(res, (i - k) * cur);
    }

    return res;
}

long long optimal(vector<int> sequence) {
    int n = sequence.size();
    vector<long long> sums(n + 1, 0);

    for (int i = 0; i < n; i++)
        sums[i + 1] = sums[i] + sequence[i];

    long long best = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            best = max(best, (j - i) * (sums[j] - sums[i]));

    return best;
}

void finish(vector<int> sequence) {
    cout << sequence.size() << '\n';

    for (int i = 0; i < (int) sequence.size(); i++)
        cout << sequence[i] << (i < (int) sequence.size() - 1 ? ' ' : '\n');

    assert(optimal(sequence) - alice(sequence) == K);
    exit(0);
}

int main() {
    cin >> K;

    for (int len = 1; len + 1 <= LEN_MAX; len++) {
        int sum = K + len + 1;

        if (sum <= len * A_MAX) {
            vector<int> sequence = {-1};

            for (int i = 0; i < len; i++)
                sequence.push_back(sum / len + (i < sum % len ? 1 : 0));

            finish(sequence);
        }
    }

    assert(false);
}