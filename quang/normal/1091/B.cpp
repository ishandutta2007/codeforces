#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

map<pair<int, int>, int> M;

int n;
pair<int, int> a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i].first >> b[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pair<int, int> u;
            u.first = a[i].first + b[j].first;
            u.second = a[i].second + b[j].second;
            M[u]++;
        }
    }
    pair<int, int> res;
    int ans = -1;
    for (auto u : M) {
        if (u.second > ans) {
            ans = u.second;
            res = u.first;
        }
    }
    cout << res.first << " " << res.second << endl;
    return 0;
}