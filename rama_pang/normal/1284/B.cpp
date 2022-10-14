#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> A(N);
    vector<int> low, high, has(N);
    for (int i = 0; i < N; i++) {
        int len;
        cin >> len;

        A[i].resize(len);
        vector<int> suff(len);
        for (int j = 0; j < len; j++) {
            cin >> A[i][j];
        }
        for (int j = len - 1; j >= 0; j--) {
            suff[j] = A[i][j];
            if (j < len - 1) {
                suff[j] = max(suff[j], suff[j + 1]);
            }
        }
        for (int j = 0; j + 1 < len; j++) {
            if (A[i][j] < suff[j + 1]) {
                has[i] = 1;
                break;
            }
        }
        
    }

    lint ans = 1ll * N * N;


    for (int i = 0; i < N; i++) {
        if (has[i]) continue;

        int mn = *min_element(begin(A[i]), end(A[i]));
        int mx = *max_element(begin(A[i]), end(A[i]));
        low.emplace_back(mn);
        high.emplace_back(mx);
    }

    sort(begin(low), end(low));
    sort(begin(high), end(high));

    for (int i = 0; i < low.size(); i++) {
        ans -= (int) (upper_bound(begin(high), end(high), low[i]) - begin(high));
    }


    cout << ans << "\n";


}