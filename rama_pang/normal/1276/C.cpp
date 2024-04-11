#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> num;
vector<vector<int>> grid;
vector<int> all;
pair<int, int> aa;

pair<int, int> check(int r, bool sim = false) {
    int N = 0;
    for (auto i : num) {
        N += min(i.second, r);
        if (sim) {
            for (int j = 0; j < min(i.second, r); j++) {
                all.emplace_back(i.first);
            }
        }
    }
    int c = N / r;
    if (sim) {
        grid.assign(r, vector<int>(c, 0));
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                grid[i][(j + i) % c] = all.back();
                all.pop_back();
            }
        }
    }
    if (r > c) return {0, 0};
    return {r, c};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    for (auto i : mp) {
        num.emplace_back(i);
    }
    
    sort(num.begin(), num.end(), [&](auto a, auto b) {
        return a.second < b.second;
    });

    aa = make_pair(1, 1);
    pair<int, int> tmp;
    for (int r = 1; r * r <= N; r++) {
        tmp = check(r);
        if (aa.first * aa.second < tmp.first * tmp.second) {
            aa = tmp;
        }
    }

    check(aa.first, true);
    cout << (aa.first * aa.second) << "\n";
    cout << aa.first << " " << aa.second << "\n";
    for (int i = 0; i < aa.first; i++) {
        for (int j = 0; j < aa.second; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}