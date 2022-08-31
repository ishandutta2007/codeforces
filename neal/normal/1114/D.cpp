#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> colors(N);

    for (int &color : colors)
        cin >> color;

    colors.resize(unique(colors.begin(), colors.end()) - colors.begin());
    N = colors.size();
    vector<vector<int16_t>> dp(N + 1, vector<int16_t>(N + 1, 0));

    for (int i = N - 1; i >= 0; i--)
        for (int j = i + 2; j <= N; j++)
            if (colors[i] == colors[j - 1])
                dp[i][j] = dp[i + 1][j - 1] + 1;
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;

    cout << dp[0][N] << '\n';
}