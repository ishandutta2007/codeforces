#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

#define sz(x) ((int) (x).size())

const int mod = (int) 1e9 + 7;

void solve() {
    int x;
    cin >> x;
    string s;
    cin >> s;
    int len = sz(s);
    for (int i = 0; i < x; ++i) {
        int rest = len - 1 - i;
        if (rest < 0) rest += mod;
        string tail;
        if (sz(s) < x) {
            tail = s.substr(i + 1, rest);
        }
        for (int it = 1; it < (s[i] - '0'); ++it) {
            len += rest;
            if (len >= mod) len -= mod;
            if (sz(s) < x) {
                s += tail; 
            }
        }
    }
    cout << len << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
}