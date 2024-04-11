#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    rep(z, q) {
        string s, t, p;
        cin >> s >> t >> p;
        vector<int> a(26);
        for (char c : t)
            a[c - 'a']--;
        for (char c : s + p)
            a[c - 'a']++;
        int pos = 0, f = 0;
        rep(i, s.size()) {
            while (pos < t.size() && t[pos] != s[i])
                pos++;
            if (pos == t.size()) {
                f = 1;
                break;
            }
            pos++;
        }
        rep(i, 26)
            if (a[i] < 0)
                f = 1;
        if (f)
            cout << "NO\n";
        else
            cout << "YES\n";
    }       
}