#include <bits/stdc++.h>
#define testcase int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
#define db(x) cout << #x << " is " << x << "\n"
using namespace std;
using lint = long long;

int N;
vector<int> A;
lint solve(lint x) {
    vector<lint> B(N);
    vector<pair<lint, lint>> tmp;
    for (int i = 0; i < N; i++) {
        B[i] = A[i] % x;
    }
    lint res = 0;
    lint sum = 0;
    for (int i = 0; i < N; i++) {
        if (x - sum < B[i]) {
            tmp.emplace_back(x - sum, i);
            B[i] = sum + B[i] - x;
            sum = x;
            i--;

        } else {
            sum += B[i];
            tmp.emplace_back(B[i], i);
            B[i] = 0;
        }

        if (sum == x) {
            lint med = 0;
            int cur = 0;
            while (true) {
                med += tmp[cur].first;
                if (2 * med >= x) {
                    med = tmp[cur].second;
                    break;
                }
                cur++;
            }

            for (auto j : tmp) {
                res += j.first * abs(j.second - med);
            }
            tmp.clear();
            sum = 0;
        }
    }
    // cout << x << " " << res << "\n";
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    lint sum = 0;
    for (int i = 0; i < N; i++) sum += A[i];
    if (sum <= 1) {
        cout << -1 << "\n";
        return 0;
    }
    lint ans = 1e18;
    for (lint div = 2; div * div <= sum; div++) {
        if (sum % div == 0) {
            while (sum % div == 0) {
                sum /= div;
            }   
            ans = min(ans, solve(div));
        }
    }

    if (sum > 1) {
        ans = min(ans, solve(sum));
    }

    cout << ans << "\n";
    return 0;

}