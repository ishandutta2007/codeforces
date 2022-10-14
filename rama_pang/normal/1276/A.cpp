#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int T = 1;
int W = 2;
int O = 3;
int N = 4;
int E = 5;
vector<int> ans;
vector<int> A;

vector<int> memo[6][6];
int dp(int n, int last2, int last1) {
    if (n == A.size()) {
        return 0;
    }
    if (memo[last2][last1][n] != -1) {
        return memo[last2][last1][n];
    }
    int& res = memo[last2][last1][n] = 1e7;
    res = min(res, 1 + dp(n + 1, last2, last1));
    if (!(last2 == T && last1 == W && A[n] == O) && !(last2 == O && last1 == N && A[n] == E)) {
        res = min(res, dp(n + 1, last1, A[n]));
    }
    return res;
}

int bt(int n, int last2, int last1) {
    if (n == A.size()) {
        return 0;
    }
    int res = dp(n, last2, last1);
    if (res == 1 + dp(n + 1, last2, last1)) {
        ans.emplace_back(n + 1);
        bt(n + 1, last2, last1);
    } else {
        bt(n + 1, last1, A[n]);
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int k;
    cin >> k;
    while (k--) {
        string s;
        cin >> s;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                memo[i][j].clear();
                memo[i][j].assign(s.size(), -1);
            }
        }
        A.clear();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 't') {
                A.emplace_back(T);
            } else if (s[i] == 'w') {
                A.emplace_back(W);
            } else if (s[i] == 'o') {
                A.emplace_back(O);
            } else if (s[i] == 'n') {
                A.emplace_back(N);
            } else if (s[i] == 'e') {
                A.emplace_back(E);
            } else {
                A.emplace_back(0);
            }
        }
        ans.clear();
        dp(0, 0, 0);
        bt(0, 0, 0);
        cout << ans.size() << "\n";
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }


}