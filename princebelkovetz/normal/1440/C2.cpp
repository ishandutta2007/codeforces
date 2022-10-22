#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
struct elem {
    int a, b, c, d, e, f;
};
vector <string> a;
void change(int x, int y, vector <elem> &ans) {
    vector <pair <int, int>> one, nil;
    if (a[x][y] == '1') one.push_back({ x, y });
    else nil.push_back({ x, y });
    if (a[x + 1][y] == '1') one.push_back({ x + 1, y });
    else nil.push_back({ x + 1, y });
    if (a[x][y + 1] == '1') one.push_back({ x, y + 1 });
    else nil.push_back({ x, y + 1 });
    if (a[x + 1][y + 1] == '1') one.push_back({ x + 1, y + 1 });
    else nil.push_back({ x + 1, y + 1 });
    a[x][y] = '0';
    a[x + 1][y] = '0';
    a[x][y + 1] = '0';
    a[x + 1][y + 1] = '0';
    if (one.empty()) return;
    if (one.size() == 3) {
        ans.push_back({ one[0].first, one[0].second, one[1].first, one[1].second, one[2].first, one[2].second });
    } 
    else if (one.size() == 2) {
        ans.push_back({ one[0].first, one[0].second, nil[0].first, nil[0].second, nil[1].first, nil[1].second });
        ans.push_back({ one[1].first, one[1].second, nil[0].first, nil[0].second, nil[1].first, nil[1].second });
    }
    else if (one.size() == 1) {
        ans.push_back({ one[0].first, one[0].second, nil[0].first, nil[0].second, nil[2].first, nil[2].second });
        ans.push_back({ one[0].first, one[0].second, nil[0].first, nil[0].second, nil[1].first, nil[1].second });
        ans.push_back({ one[0].first, one[0].second, nil[1].first, nil[1].second, nil[2].first, nil[2].second });
    }
    else {
        for (int i = 1; i < 4; ++i) nil.push_back(one[i]);
        ans.push_back({ one[1].first, one[1].second, one[2].first, one[2].second, one[3].first, one[3].second });
        ans.push_back({ one[0].first, one[0].second, nil[0].first, nil[0].second, nil[2].first, nil[2].second });
        ans.push_back({ one[0].first, one[0].second, nil[0].first, nil[0].second, nil[1].first, nil[1].second });
        ans.push_back({ one[0].first, one[0].second, nil[1].first, nil[1].second, nil[2].first, nil[2].second });
    }
}
void sw(char &x) {
    if (x == '1') x = '0';
    else x = '1';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, m; cin >> n >> m;
        a.resize(n);
        for (auto& x : a) 
            cin >> x;
        vector <elem> ans;
        if (n % 2 == 1 and m % 2 == 1) {
            for (int j = 0; j < m - 1; ++j) {
                if (a[n - 1][j] == '1') {
                    sw(a[n - 1][j]);
                    sw(a[n - 2][j]);
                    sw(a[n - 2][j + 1]);
                    ans.push_back({ n - 1, j, n - 2, j, n - 2, j + 1 });
                }
            }
            for (int i = n - 1; i > 0; --i) {
                if (a[i][m - 1] == '1') {
                    sw(a[i][m - 1]);
                    sw(a[i - 1][m - 1]);
                    sw(a[i - 1][m - 2]);
                    ans.push_back({ i, m - 1, i - 1, m - 1, i - 1, m - 2 });
                }
            }
            if (a[0][m - 1] == '1') {
                sw(a[0][m - 1]);
                sw(a[0][m - 2]);
                sw(a[1][m - 2]);
                ans.push_back({ 0, m - 1, 0, m - 2, 1, m - 2 });
            }
        }
        else if (n % 2 == 1) {
            for (int j = 0; j < m - 1; ++j) {
                if (a[n - 1][j] == '1') {
                    sw(a[n - 1][j]);
                    sw(a[n - 2][j]);
                    sw(a[n - 2][j + 1]);
                    ans.push_back({ n - 1, j, n - 2, j, n - 2, j + 1 });
                }
            }
            if (a[n - 1][m - 1] == '1') {
                sw(a[n - 1][m - 1]);
                sw(a[n - 2][m - 1]);
                sw(a[n - 2][m - 2]);
                ans.push_back({ n - 1, m - 1, n - 2, m - 1, n - 2, m - 2 });
            }
        } 
        else if (m % 2 == 1) {
            for (int i = n - 1; i > 0; --i) {
                if (a[i][m - 1] == '1') {
                    sw(a[i][m - 1]);
                    sw(a[i - 1][m - 1]);
                    sw(a[i - 1][m - 2]);
                    ans.push_back({ i, m - 1, i - 1, m - 1, i - 1, m - 2 });
                }
            }
            if (a[0][m - 1] == '1') {
                sw(a[0][m - 1]);
                sw(a[0][m - 2]);
                sw(a[1][m - 2]);
                ans.push_back({ 0, m - 1, 0, m - 2, 1, m - 2 });
            }
        }
        for (int i = 0; i < n - 1; i += 2) {
            for (int j = 0; j < m - 1; j += 2) {
                change(i, j, ans);
            }
        }
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x.a + 1 << ' ' << x.b + 1 << ' ' << x.c + 1 << ' ' << x.d + 1 << ' ' << x.e + 1 << ' ' << x.f + 1 << '\n';
    }
	return 0;
}