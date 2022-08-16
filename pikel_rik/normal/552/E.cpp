#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

pair<ll, ll> parse(const string& s, bool want1 = false, bool want2 = false) {
    string cur;
    vector<string> v;

    for (int i = 0; i < s.length(); i += 2) {
        cur += s[i];
        if (i + 1 < s.length() and s[i + 1] == '+') {
            v.push_back(cur);
            cur.clear();
        }
    }

    v.push_back(cur);
    ll ans = 0, fr = 0, bk = 0;

    for (int i = 0; i < v.size(); i++) {
        string str = v[i];
        ll now = 1;
        for (char c : str)
            now = now * (c - '0');

        if (i == 0) {
            fr = now;
        }
        if (i == v.size() - 1) {
            bk = now;
        }
        ans += now;
    }
    if (want1)
        return {ans, fr};
    return {ans, bk};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    ll mx = parse(s).first;
    vector<int> pos;

    for (int i = 1; i < s.length(); i += 2) {
        if (s[i] == '*') {
            auto p1 = parse(s.substr(0, i), false, true);
            auto p2 = parse(s.substr(i + 1, s.length()), true, false);

            mx = max(mx, p1.first - p1.second + p1.second * p2.first);
            mx = max(mx, p2.first - p2.second + p1.first * p2.second);
            pos.push_back(i);
        }
    }

    for (int i = 0; i < pos.size(); i++) {
        for (int j = i + 1; j < pos.size(); j++) {
            auto p1 = parse(s.substr(0, pos[i]), false, true);
            auto p2 = parse(s.substr(pos[i] + 1, pos[j] - pos[i] - 1));
            auto p3 = parse(s.substr(pos[j] + 1, s.length()), true, false);

            mx = max(mx, p1.first - p1.second + p3.first - p3.second + p1.second * p2.first * p3.second);
        }
    }

    cout << mx << "\n";
    return 0;
}