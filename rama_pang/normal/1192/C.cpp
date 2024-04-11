#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint MOD = 998244353;

int N;
array<vector<pair<int, int>>, 11> words;
set<string> in;
/*
Let dp[a][b][c] = number of word triples which begin with same letter, and end with a, b, and c
then ans = dp[a][b][c] * dp[a][b][d] * dp[a][c][d] * dp[b][c][d]  for all a, b, c, d = each letter in set
use symetry to reduce constant by a factor of 6 and 24
*/
void read() {
    string s, si; cin >> s;
    reverse(s.begin(), s.end());
    si = s;
    reverse(s.begin(), s.end());
    //62 letters in total
    int st, et;
    if ('a' <= s.front() && s.front() <= 'z') {
        st = s.front() - 'a';
    } else if ('A' <= s.front() && s.front() <= 'Z') {
        st = s.front() - 'A' + 26;
    } else if ('0' <= s.front() && s.front() <= '9') {
        st = s.front() - '0' + 26 + 26;
    }
    swap(s.front(), s.back());
    if ('a' <= s.front() && s.front() <= 'z') {
        et = s.front() - 'a';
    } else if ('A' <= s.front() && s.front() <= 'Z') {
        et = s.front() - 'A' + 26;
    } else if ('0' <= s.front() && s.front() <= '9') {
        et = s.front() - '0' + 26 + 26;
    }
    swap(s.front(), s.back());

    if (in.find(s) == in.end()) words[s.size()].emplace_back(st, et);
    in.insert(s);
    if (in.find(si) == in.end()) words[s.size()].emplace_back(et, st);
    in.insert(si);
}

inline lint perm(int a, int b, int c, int d) {
    if (a == b && b == c && c == d) return 1;
    if ((a == b && b == c) || (a == b && b == d) || (a == c && c == d) || (b == c && c == d)) return 4;
    if (a == b && c == d) return 6;
    if (a == b || a == c || a == d || b == c || b == d || c == d) return 12;
    return 24;
}

lint solve(array<array<lint, 62>, 62> cnt) {
    /* Precompute DP */
    array<array<array<lint, 62>, 62>, 62> dp = {};
    for (int a = 0; a < 62; a++) {
        for (int b = a; b < 62; b++) {
            for (int c = b; c < 62; c++) {
                for (int m = 0; m < 62; m++) { //middle, can be anything
                    dp[a][b][c] += cnt[m][a] * cnt[m][b] * cnt[m][c];
                    dp[a][b][c] %= MOD;
                }
            }
        }
    }

    lint res = 0;
    for (int a = 0; a < 62; a++) {
        for (int b = a; b < 62; b++) {
            for (int c = b; c < 62; c++) {
                for (int d = c; d < 62; d++) {
                    res += ((((dp[a][b][c] * dp[a][b][d]) % MOD) * ((dp[a][c][d] * dp[b][c][d]) % MOD)) % MOD) * perm(a, b, c, d);
                    res %= MOD;
                }
            }
        }
    }
    // cerr << res << "\n";
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) read();

    lint ans = 0;
    for (int i = 3; i <= 10; i++) {
        array<array<lint, 62>, 62> cnt = {};
        for (auto j : words[i]) cnt[j.first][j.second]++;
        // for (auto j : words[i]) cerr << j.first << " " << j.second << "\n";
        ans += solve(cnt); ans %= MOD;
    }
    cout << ans << "\n";
}