#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct project {
    int A, B;

    bool operator<(const project &other) const {
        return A + B > other.A + other.B;
    }
};

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

    int completed = 0;

    while (true) {
        int index = -1;

        for (int i = 0; i < (int) positive.size(); i++)
            if (R >= positive[i].A)
                index = i;

        if (index < 0)
            break;

        R += positive[index].B;
        completed++;
        positive.erase(positive.begin() + index);
    }

    sort(negative.begin(), negative.end());
    vector<int> dp(R + 1, completed);

    for (project &proj : negative)
        for (int i = proj.A; i <= R; i++)
            if (i + proj.B >= 0)
                dp[i + proj.B] = max(dp[i + proj.B], dp[i] + 1);

    int answer = *max_element(dp.begin(), dp.end());
    cout << (answer == N ? "YES" : "NO") << '\n';
}