#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<int> f;

void init(int n) {
    f.assign(n + 1, 0);
}

long sum(int r) { // exclusive
    if (r == 0)
        return 0;
    r--;
    long result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        result += f[r];
    return result;
}

void inc(int i) {
    for (; i < f.size(); i = (i | (i + 1)))
        f[i] ++;
}

int sum(int l, int r) {
    return (r - l + 1) - (sum(r) - sum(l - 1));
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    set<int> s;
    long res = 0;
    auto p = s.begin();
    int pos = 0;
    init(n);

    for (int i = 0; i < n; i++) {
        int u = a[i].second;
        int x = sum(u);
        res -= min(x, i - x);
        res += (i - x);
        inc(u);
        s.insert(u);
        if (i == 0) {
            p = s.begin();
        } else {
            if (u < *p) {
                pos++;
            }
            int dis = i / 2;
            while (pos > dis) {
                pos--;
                --p;
            }
            while (pos < dis) {
                pos++;
                ++p;
            }
            if (i % 2 == 1 && u <= *p) {
                pos++;
                ++p;
            }
        }
//        cout << i << " " << u << " " << x << " " << pos << " " << *p << "\n";
        res += abs(u - *p) - abs(pos - x);
        cout << res << "\n";
    }

    return 0;
}