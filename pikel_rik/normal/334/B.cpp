#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

pair<int, int> a[8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (auto &i : a)
        cin >> i.first >> i.second;

    sort(a, a + 8);
    set<int> x, y;

    for (auto i : a)
        x.insert(i.first), y.insert(i.second);

    if (x.size() != 3 or y.size() != 3) {
        cout << "ugly\n";
        return 0;
    }

    vector<pair<int, int>> v;
    for (int i : x) for (int j : y) v.push_back({i, j});

    for (auto i : a) {
        if (i.first == v[4].first and i.second == v[4].second) {
            cout << "ugly\n";
            return 0;
        }
    }

    v.erase(v.begin() + 4);

    for (auto i : v) {
        bool flag = false;
        for (auto p : a) {
            if (p.first == i.first and p.second == i.second)
                flag = true;
        }
        if (!flag) {
            cout << "ugly\n";
            return 0;
        }
    }

    cout << "respectable\n";
    return 0;
}