#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bool check(pair<int, int> u, pair<int, int> v, pair<int, int> w) {
    // cout << u.first << ' ' << u.second << endl;
    // cout << v.first << ' ' << v.second << endl;
    // cout << w.first << ' ' << w.second << endl;
    long long d = u.first - v.first;
    long long dx = (1ll * u.second - 1ll * u.first * u.first) - (1ll * v.second - 1ll * v.first * v.first);
    long long dy = 1ll * u.first * (1ll * v.second - 1ll * v.first * v.first) - 1ll * v.first * (1ll * u.second - 1ll * u.first * u.first);
    // cout << d << ' ' << dx << ' ' << dy << endl;
    long long foo = d * w.first * w.first + dx * w.first + dy;
    if (d > 0) return foo <= d * w.second;
    else return foo >= d * w.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &u : a) cin >> u.first >> u.second;
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    for (auto u : a) {
        if (b.empty()) b.push_back(u);
        else {
            if (b.back().first != u.first) b.push_back(u);
            else b.back().second = u.second;
        }
    }
    vector<pair<int, int>> st;
    for (auto u : b) {
        if (st.empty()) st.push_back(u);
        else {
            while (st.size() >= 2 && check(st[st.size() - 2], st[st.size() - 1], u)) st.pop_back();
            st.push_back(u); 
        }
    }
    cout << st.size() - 1 << endl;
    return 0;
}