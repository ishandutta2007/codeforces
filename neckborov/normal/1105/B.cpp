//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

const old PI = acos(-1.0);

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int kek = 0;
    vector<int> cnt(26);
    int len = 0;
    s += '#';
    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            ++len;
        } else {
            if (s[i] == s[i - 1]) {
                ++len;
            } else {
                cnt[s[i - 1] - 'a'] += len / k;
                len = 1;
            }
        }
    }
    cout << *max_element(cnt.begin(), cnt.end());
    return 0;
}