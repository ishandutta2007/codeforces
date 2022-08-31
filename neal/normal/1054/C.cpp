#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(N), R(N);

    for (int i = 0; i < N; i++)
        cin >> L[i];

    for (int i = 0; i < N; i++)
        cin >> R[i];

    for (int i = 0; i < N; i++)
        if (L[i] + R[i] >= N) {
            cout << "NO" << '\n';
            return 0;
        }

    vector<pair<int, int>> sorted;

    for (int i = 0; i < N; i++)
        sorted.emplace_back(L[i] + R[i], i);

    sort(sorted.begin(), sorted.end());
    vector<int> candies(N);
    int count = N;

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && sorted[i].first == sorted[j].first)
            j++;

        for (int k = i; k < j; k++)
            candies[sorted[k].second] = count;

        count--;
    }

    for (int i = 0; i < N; i++) {
        int count_left = 0, count_right = 0;

        for (int j = 0; j < N; j++)
            if (candies[j] > candies[i])
                j < i ? count_left++ : count_right++;

        if (L[i] != count_left || R[i] != count_right) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';

    for (int i = 0; i < N; i++)
        cout << candies[i] << (i < N - 1? ' ' : '\n');
}