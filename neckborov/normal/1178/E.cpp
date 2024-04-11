//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    int lent = n / 2;
    vector<int> pos[3];
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    string t;
    int l = -1, r = n;
    while (t.length() < lent && l + 2 < r) {
        int ni[3], nj[3];
        for (int i = 0; i < 3; i++) {
            ni[i] = upper_bound(pos[i].begin(), pos[i].end(), l) - pos[i].begin();
        }
        for (int i = 0; i < 3; i++) {
            nj[i] = lower_bound(pos[i].begin(), pos[i].end(), r) - pos[i].begin() - 1;
        }
        vector<int> len(3);
        for (int i = 0; i < 3; i++) {
            if (ni[i] >= 0 && ni[i] < pos[i].size()) {
                len[i] += pos[i][ni[i]] - l;
            } else {
                len[i] = n + 1;
            }
            if (nj[i] >= 0 && nj[i] < pos[i].size()) {
                len[i] += r - pos[i][nj[i]];
            } else {
                len[i] = n + 1;
            }
        }
        int posb = min_element(len.begin(), len.end()) - len.begin();
        if (len[posb] >= r - l) {
            break;
        } else {
            l = pos[posb][ni[posb]];
            r = pos[posb][nj[posb]];
            t += char('a' + posb);
        }
    }
    int m = t.length();
    if (l + 1 < r) {
        t += s[l + 1];
    }
    for (int i = 0; i < m; i++) {
        t += t[m - i - 1];
    }
    if (t.length() >= lent) {
        cout << t;
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}