#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll INF = 2e18;
const int INFi = 2e9;


void solve() {
    map<char, int> cnt;
    string s; cin >> s;
    for(auto &c : s) cnt[c]++;
    string kek = "ANOT";
    pair<ll, string> ans = {-1, ""};
    do {
        auto cnt2 = cnt;
        string s2 = "";
        for(auto &c : kek) {
            range(_, cnt[c]) s2 += c;
        }
        ll res = 0;
        for(auto &c : s) {
            for(auto &c2 : kek) {
                if (c2 == c) {
                    cnt2[c2]--;
                    break;
                }
                res += cnt2[c2];
            }
        }
        ans = max(ans, {res, s2});
    } while(next_permutation(all(kek)));
    cout << ans.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}