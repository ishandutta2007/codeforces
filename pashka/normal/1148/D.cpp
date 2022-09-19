#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

vector<int> solve(vector<pair<int, int>> a) {
    map<int, int> d;
    for (int i = 0; i < a.size(); i++) {
        auto p = a[i];
        if (p.second > p.first) {
            d[p.first] = i;
        }
    }
    vector<int> res;
    for (auto p : d) {
        res.push_back(p.second);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> best1 = solve(a);
    for (int i = 0; i < n; i++) {
        swap(a[i].first, a[i].second);
    }
    vector<int> best2 = solve(a);
    reverse(best2.begin(), best2.end());

    vector<int> &best = best1.size() > best2.size() ? best1 : best2;
    cout << best.size() << "\n";
    for (int x : best) {
        cout << x + 1 << " ";
    }

    return 0;
}