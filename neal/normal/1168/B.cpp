#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
string S;
vector<int> locations[2];
vector<int> closest_right;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();

    for (int i = 0; i < N; i++)
        locations[S[i] - '0'].push_back(i);

    closest_right.assign(N, INF);

    for (int i = 0; i < N; i++) {
        vector<int> &locs = locations[S[i] - '0'];
        auto it = lower_bound(locs.begin(), locs.end(), i);
        it++;

        while (it != locs.end()) {
            int right = 2 * (*it) - i;

            if (right >= N)
                break;

            if (S[right] == S[i]) {
                closest_right[i] = right;
                break;
            }

            it++;
        }
    }

    long long total = 0;
    int best = N;

    for (int i = N - 1; i >= 0; i--) {
        best = min(best, closest_right[i]);
        total += N - best;
    }

    cout << total << '\n';
}