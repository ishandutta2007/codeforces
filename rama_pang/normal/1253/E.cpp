#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> A;
int memo[85][100005];

int dp(int n, int d) { // d = distance so far
    if (d >= M) {
        return 0;
    } else if (n == N) {
        return max(0, M - d);
    } else if (memo[n][d] != -1) {
        return memo[n][d];
    }

    int &res = memo[n][d] = 1e9;
    for (int i = n + 1; i < N; i++) {
        int tmp;
        tmp = max(0, A[i].first - d - 1) + dp(i, A[i].second + max(0, A[i].first - d - 1));
        res = min(res, tmp);
    }
    res = min(res, 1 + dp(n, d + 1));

    return res;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    memset(memo, -1, sizeof(memo));

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, s; cin >> x >> s;
        A.emplace_back(max(1, x - s), min(M, x + s));
    }
    sort(A.begin(), A.end(), [&](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    vector<pair<int, int>> tmp;
    tmp.emplace_back(0, 0);
    for (auto i : A) {
        if (!(!tmp.empty() && tmp.back().first <= i.first && i.second <= tmp.back().second)) {
            tmp.emplace_back(i);
        }
    }
    
    A = tmp;
    N = A.size();

    cout << dp(0, 0) << "\n";


}