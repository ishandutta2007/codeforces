#include <bits/stdc++.h>
using namespace std;

/**
 * DP[i] = DP[k] + B[k] * A[i], 0 <= k < i
 * 
**/
using lint = long double;
const lint INF = 1e19;

int N;
lint A[100005], B[100005];
lint DP[100005];

struct Hull {
    vector<pair<lint, lint>> H;
    int sz = 1, ptr = 0;
    void init(int n) {
        H.assign(2 * n, make_pair(0, INF));
    }
    void insert(lint m, lint c) {
        /**
         * m1x + c1 = mx + c
         * m1x - mx = c - c1
         * x = (c - c1) / (m1 - m)
         * m2x + c2 = m1x + c1
         * x = (c1 - c2) / (m2 - m1)
         * 
         * (c - c1) / (m1 - m) < (c1 - c2) / (m2 - m1)
         * (c - c1) * (m2 - m1) < (c1 - c2) * (m1 - m)
        **/
        
        H[sz] = {m, c};
        while (ptr <= sz - 2 && (1.00 * H[sz].second - H[sz - 2].second) / (H[sz - 2].first - H[sz].first)  <
                                (1.00 * H[sz - 2].second - H[sz - 1].second) / (H[sz - 1].first - H[sz - 2].first) ) {
            H[sz - 1] = H[sz];
            sz--;
        }
        sz++;
    }

    lint query(lint x) {
        while (ptr + 1 < sz && H[ptr + 1].first * x + H[ptr + 1].second < 
                               H[ptr].first * x + H[ptr].second) {
            ptr++;
        }
        return H[ptr].first * x + H[ptr].second;
    }

} hull;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = a;
    }
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        B[i] = a;
    }
    hull.init(N);
    DP[0] = 0;
    hull.insert(B[0], DP[0]);
    for (int i = 1; i <= N; i++) {
        DP[i] = hull.query(A[i]);
        hull.insert(B[i], DP[i]);
    }

    cout << (long long)DP[N - 1] << "\n";
    return 0;
}