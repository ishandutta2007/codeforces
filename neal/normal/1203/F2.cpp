#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct project {
    int A, B;
};

bool compare_positive(const project &x, const project &y) {
    return x.A < y.A;
}

bool compare_negative(const project &x, const project &y) {
    return x.A + x.B > y.A + y.B;
}

int N, R;
vector<project> positive, negative;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R;

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;

        if (B >= 0)
            positive.push_back({A, B});
        else
            negative.push_back({A, B});
    }

    sort(positive.begin(), positive.end(), compare_positive);
    sort(negative.begin(), negative.end(), compare_negative);
    int completed = 0;

    for (project &proj : positive)
        if (R >= proj.A) {
            R += proj.B;
            completed++;
        }

    vector<int> dp(N + 1, -INF);
    dp[0] = R;

    for (int p = 0; p < (int) negative.size(); p++)
        for (int i = p; i >= 0; i--)
            if (dp[i] >= negative[p].A)
                dp[i + 1] = max(dp[i + 1], dp[i] + negative[p].B);

    int answer = 0;

    while (answer < N && dp[answer + 1] >= 0)
        answer++;

    answer += completed;
    cout << answer << '\n';
    // cout << (answer == N ? "YES" : "NO") << '\n';
}