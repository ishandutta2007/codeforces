#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> freq(K + 1, 0);

    for (int i = 0; i < N; i++) {
        int drink;
        cin >> drink;
        freq[drink]++;
    }

    int sets = (N + 1) / 2;
    int favorite = 0;
    int singles = 0;

    for (int k = 1; k <= K; k++) {
        sets -= freq[k] / 2;
        favorite += 2 * (freq[k] / 2);

        if (freq[k] % 2 == 1)
            singles++;
    }

    favorite += min(sets, singles);
    cout << favorite << '\n';
}