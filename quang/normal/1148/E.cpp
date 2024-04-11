#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int  t[N];
int a[N];
pair<int, int> s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    sort(s + 1, s + n + 1);
    sort(t + 1, t + n + 1);

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = t[i] - s[i].first;
        sum += a[i];
        // cout << a[i] << ' ';
    }
    // cout << endl;
    if (sum != 0) {
        cout << "NO\n";
        return 0;
    }
    vector<tuple<int, int, int>> res;
    res.reserve(n);

    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (a[i] < 0 && !st.empty()) {
            int id = st.back();
            if (a[id] > -a[i]) {
                res.push_back({id, i, -a[i]});
                a[id] += a[i];
                a[i] = 0;
                break;
            } else {
                res.push_back({id, i, a[id]});
                a[i] += a[id];
                a[id] = 0;
                st.pop_back();
            }
        }
        if (a[i] < 0 && st.empty()) {
            cout << "NO\n";
            return 0;
        }
        if (a[i] > 0) st.push_back(i);
    }
    cout << "YES\n";
    cout << res.size() << '\n';
    for (auto u : res) {
        cout << s[get<0>(u)].second << ' ' << s[get<1>(u)].second << ' ' << get<2>(u) << '\n';
    }
    return 0;
}