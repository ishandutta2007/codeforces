#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int get(std::vector<int>& v, int N) {
    int n = v.size();
    vector<int> zalgo(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            zalgo[i] = min (r - i + 1, zalgo[i - l]);
        while (i + zalgo[i] < n && v[zalgo[i]] == v[i + zalgo[i]])
            ++zalgo[i];
        if (i + zalgo[i] - 1 > r)
            l = i, r = i + zalgo[i] - 1;
    }
    int j = 0;
    for (int i = 1; i < n; ++i) {
        if (zalgo[i] == n - i && (n % (i) == 0)) {
            j = i;
            break;
        } 
    }
    if (j == 0) return N;
    int re = 0;
    for (int i = 0; i < j; ++i) {
        re += v[i];
    } 
    return re;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int m; cin >> m;
    std::vector<int> v[n + 3];
    for (int i = 0; i < m; ++i) {
        int a; cin >> a;
        int b; cin >> b;
        if (abs(a - b) < n - abs(a - b)) {
            if (a > b)
                swap(a, b);
            v[abs(a - b)].pb(a);
        } else {
            if (a > b)
                swap(a, b);
            v[n - abs(a - b)].pb(b);
        }
    }
    int res = 1;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        if (v[i].empty()) continue;
        if (i * 2 == n) {
            int y = v[i].size();
            for (int j = 0; j < y; ++j)
                v[i].pb((v[i][j] + i) % n);
        }
        if (v[i].size() == 1) {
            ok = false;
            break;
        } 
        std::vector<int> v1;
        sort(v[i].begin(), v[i].end());
        v1.pb(v[i][0] + n - v[i][v[i].size() - 1]);
        for (int j = 1; j < v[i].size(); ++j)
            v1.pb(v[i][j] - v[i][j - 1]);
        int rr = get(v1, n);
        int g = __gcd(rr, res);
        res = (res * rr) / g;
        if (res >= n) {
            ok = false;
            break;
        } 
    }
    if (!ok) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}