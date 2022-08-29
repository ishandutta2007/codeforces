#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string HARD = "hard";

int N;
string S;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    vector<long long> dp(5, 0);

    for (int i = 0; i < N; i++) {
        std::size_t index = HARD.find(S[i]);

        if (index == string::npos)
            continue;

        dp[index + 1] = min(dp[index + 1], dp[index]);
        dp[index] += A[i];
    }

    cout << *min_element(dp.begin(), dp.begin() + 4) << '\n';
}