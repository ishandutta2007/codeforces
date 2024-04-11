#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

bool solve(string s, string t) {
    int n = s.size();
    map<pair<char, char>, int> mp;
    for (int i = 0; i < n; i++) {
        pair<char, char> p = {s[i], t[n - i - 1]};
        if (p.first > p.second) swap(p.first, p.second);
        mp[p] += 1;
    }
    int cnt = 0;
    for (auto to : mp) {
        cnt += to.second % 2;
        if (to.second % 2 == 1) {
            if (to.first.first != to.first.second) {
                cnt = 2;
            }
        }
    }
    return cnt <= 1;
}

signed main() {
#ifdef LOCAL
   // freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        cout << (solve(a, b) ? "YES" : "NO") << endl;
    }
    return 0;
}