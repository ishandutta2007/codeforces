//
// Created by Ormlis on 27.11.2019.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
#define pb(el) push_back(el)
using namespace std;

ll MOD = 998244353;
ll INF = 1e18 * 2;
int INF2 = 1e9 * 2;

int used[100][100];
int n, m;

void solve() {
    string s;
    cin >> s;
    char prev = '=';
    n = (int)s.size();
    for(int i = 0; i < n; ++i) {
        if (s[i] == prev) {
            cout << -1 << '\n';
            return;
        }
        if (s[i] == '?') {
            int flag_a = 1, flag_b = 1, flag_c = 1;
            if (prev == 'a' || (i + 1 < n && s[i + 1] == 'a')) flag_a = 0;
            if (prev == 'b' || (i + 1 < n && s[i + 1] == 'b')) flag_b = 0;
            if (prev == 'c' || (i + 1 < n && s[i + 1] == 'c')) flag_c = 0;
            if (flag_a) s[i] = 'a';
            else if (flag_b) s[i] = 'b';
            else if (flag_c) s[i] = 'c';
            else {
                cout << -1 << '\n';
                return;
            }
        }
        prev = s[i];
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}