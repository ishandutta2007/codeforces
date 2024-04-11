#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> x(n), y(n);
        for (auto &z : x) cin >> z;
        for (auto &z : y) cin >> z;

        vector<int> positive, negative;
        for (int i = 0; i < n; i++) {
            if (y[i] - x[i] >= 0) {
                positive.push_back(y[i] - x[i]);
            } else {
                negative.push_back(y[i] - x[i]);
            }
        }

        sort(positive.rbegin(), positive.rend());
        sort(negative.begin(), negative.end());

        int answer = 0;
        for (int i = 0, j = 0; i < (int) positive.size(); i++) {
            while (j < (int) negative.size() && negative[j] + positive[i] < 0) {
                j += 1;
            }
            if (j < (int) negative.size()) {
                answer += 1;
                j += 1;
            } else {
                answer += ((int)positive.size() - i) / 2;
                break;
            }
        }

        cout << answer << '\n';
    }
    return 0;
}