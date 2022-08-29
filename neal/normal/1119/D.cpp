#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<long long> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    S.resize(N);

    for (long long &s : S)
        cin >> s;

    sort(S.begin(), S.end());
    vector<long long> gaps;

    for (int i = 0; i < N - 1; i++)
        gaps.push_back(S[i + 1] - S[i]);

    sort(gaps.begin(), gaps.end());
    vector<long long> gap_sums(N, 0);

    for (int i = 0; i < N - 1; i++)
        gap_sums[i + 1] = gap_sums[i] + gaps[i];

    cin >> Q;

    for (int q = 0; q < Q; q++) {
        long long L, R;
        cin >> L >> R;
        long long D = R - L + 1;

        int position = lower_bound(gaps.begin(), gaps.end(), D) - gaps.begin();
        long long answer = gap_sums[position] + (N - position) * D;
        cout << answer << (q < Q - 1 ? ' ' : '\n');
    }
}