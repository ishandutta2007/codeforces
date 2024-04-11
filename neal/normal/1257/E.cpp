#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Finds the length of the longest subsequence of values such that compare is true for all consecutive pairs.
template<typename T, typename T_compare>
int longest_increasing_subsequence(vector<T> values, T_compare &&compare) {
    vector<T> best_ending;

    for (T value : values) {
        auto it = lower_bound(best_ending.begin(), best_ending.end(), value, compare);

        if (it == best_ending.end())
            best_ending.push_back(value);
        else
            *it = value;
    }

    return best_ending.size();
}

const int P = 3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K[P];
    int N = 0;

    for (int p = 0; p < P; p++) {
        cin >> K[p];
        N += K[p];
    }

    vector<int> who(N, -1);

    for (int p = 0; p < P; p++)
        for (int k = 0; k < K[p]; k++) {
            int a;
            cin >> a;
            a--;
            who[a] = p;
        }

    cout << N - longest_increasing_subsequence(who, less_equal<int>()) << '\n';
}