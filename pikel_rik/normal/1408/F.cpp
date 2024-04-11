#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 15000 + 5;

int n;
vector<pair<int, int>> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int highBit = 1 << (32 - __builtin_clz(n) - 1);
    for (int rot = 0, offset = 0; rot < 2; rot++) {
        for (int l = 2; l <= highBit; l <<= 1) {
            for (int i = 1; i <= highBit; i += l) {
                for (int j = i; j < i + l / 2; j++) {
                    ans.emplace_back(j + offset, j + l / 2 + offset);
                }
            }
        }
        offset = n ^ highBit;
    }

    cout << ans.size() << '\n';
    for (auto& [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
    return 0;
}