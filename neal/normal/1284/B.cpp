#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
vector<vector<int>> S;
vector<int> min_value, max_value;
vector<bool> has_ascent;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    S.assign(N, {});
    min_value.assign(N, INF);
    max_value.assign(N, -INF);
    has_ascent.assign(N, false);

    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        S[i].resize(L);

        for (int &s : S[i]) {
            cin >> s;
            has_ascent[i] = has_ascent[i] || (s > min_value[i]);
            min_value[i] = min(min_value[i], s);
            max_value[i] = max(max_value[i], s);
        }
    }

    int H = 0;
    vector<int> minimums, maximums;

    for (int i = 0; i < N; i++)
        if (has_ascent[i]) {
            H++;
        } else {
            minimums.push_back(min_value[i]);
            maximums.push_back(max_value[i]);
        }

    long long total = (long long) N * N - (long long) (N - H) * (N - H);
    sort(minimums.begin(), minimums.end());
    sort(maximums.begin(), maximums.end());

    for (int maximum : maximums)
        total += lower_bound(minimums.begin(), minimums.end(), maximum) - minimums.begin();

    cout << total << '\n';
}