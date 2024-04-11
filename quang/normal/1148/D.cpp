#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
pair<int, int> a[N];
vector<int> x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first < a[i].second) {
            x.push_back(i);
        } else {
            y.push_back(i);
            a[i].first = -a[i].first;
            a[i].second = -a[i].second;
        }
    }
    auto cmp = [&](int u, int v) {
        return a[u].first > a[v].second;
    };

    if (x.size() > y.size()) {
        sort(x.begin(), x.end(), cmp);
        cout << x.size() << endl;
        for (int u : x) cout << u << ' ';
            cout << endl;
    } else {
        sort(y.begin(), y.end(), cmp);
        cout << y.size() << endl;
        for (int u : y) cout << u << ' ';
            cout << endl;
    }
    return 0;
}