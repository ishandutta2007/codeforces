#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int A[810015], S[810015][25];
int HS[810015];
pair<int, int> H[810015];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;


    while (t--) {
        int n; cin >> n;
        for (int i = 0; i <= n + 5; i++) A[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            S[i][0] = A[i];
        }
        int m; cin >> m;
        for (int i = 0; i <= m + 5; i++) H[i] = {0, 0};
        int mxp = 0;
        for (int i = 1; i <= m; i++) {
            cin >> H[i].first >> H[i].second;
            mxp = max(mxp, H[i].first);
        }

        sort(H + 1, H + m + 1);
        for (int i = 0; i <= m + 5; i++) HS[i] = 0;
        for (int i = m; i >= 1; i--) {
            HS[i] = max(HS[i + 1], H[i].second);
        }

        if (*max_element(A + 1, A + n + 1) > mxp) {
            cout << -1 << "\n";
            continue;
        }
        int pw = floor(log2(n)) + 1;
        for (int i = 0; i <= n + 5; i++) {
            for (int j = 1; j <= pw + 1; j++) {
                S[i][j] = 0;
            }
        }
        for (int j = 1; j <= pw; j++) {
            for (int i = 1; i <= n; i++) {
                S[i][j] = max(S[i][j - 1], S[i + (1 << (j - 1))][j - 1]);
            }
        }
        auto getS = [&](int l, int r) {
            int k = floor(log2(r - l + 1));
            return max(S[l][k], S[r - (1 << (k)) + 1][k]);
        };

        int res = 0;
        for (int i = 1; i <= n; i++) {
            int le = i, ri = n;
            int ans = i;
            while (le <= ri) {
                int mid = (le + ri) / 2;
                int mn = getS(i, mid);
                int k = lower_bound(H + 1, H + m + 1, make_pair(mn, -1)) - H;
                if (HS[k] < (mid - i + 1)) {
                    ri = mid - 1;
                } else {
                    ans = mid;
                    le = mid + 1;
                }
            }
            res++;
            i = ans;
        }

        cout << res << "\n";
    }    
}