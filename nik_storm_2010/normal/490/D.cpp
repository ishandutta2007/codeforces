#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
const int INF = 2e9;

void update(int &x, int y) {
    if (x == 0 || x > y) x = y;
}

int main() {
    int a1, b1, a2, b2;
    vector <pii> aa1, bb1, aa2, bb2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    map <int, int> base;
    base[a1] = 1;
    while (!base.empty()) {
        map <int, int>::iterator it = base.end();
        it--;
        int x = it->first, y = it->second;
        aa1.push_back(make_pair(x, y - 1));
        base.erase(it);
        if (x % 2 == 0) update(base[x / 2], y + 1);
        if (x % 3 == 0) update(base[x / 3 * 2], y + 1);
    }
    base[b1] = 1;
    while (!base.empty()) {
        map <int, int>::iterator it = base.end();
        it--;
        int x = it->first, y = it->second;
        bb1.push_back(make_pair(x, y - 1));
        base.erase(it);
        if (x % 2 == 0) update(base[x / 2], y + 1);
        if (x % 3 == 0) update(base[x / 3 * 2], y + 1);
    }
    base[a2] = 1;
    while (!base.empty()) {
        map <int, int>::iterator it = base.end();
        it--;
        int x = it->first, y = it->second;
        aa2.push_back(make_pair(x, y - 1));
        base.erase(it);
        if (x % 2 == 0) update(base[x / 2], y + 1);
        if (x % 3 == 0) update(base[x / 3 * 2], y + 1);
    }
    base[b2] = 1;
    while (!base.empty()) {
        map <int, int>::iterator it = base.end();
        it--;
        int x = it->first, y = it->second;
        bb2.push_back(make_pair(x, y - 1));
        base.erase(it);
        if (x % 2 == 0) update(base[x / 2], y + 1);
        if (x % 3 == 0) update(base[x / 3 * 2], y + 1);
    }
    int ans = INF, x1, y1, x2, y2;
    for (int i1 = 0; i1 < aa1.size(); i1++) for (int j1 = 0; j1 < bb1.size(); j1++) {
        ll s1 = 1LL * aa1[i1].first * bb1[j1].first;
        int j2 = bb2.size() - 1;
        for (int i2 = 0; i2 < aa2.size(), j2 >= 0; i2++) {
            while (j2 >= 0 && s1 > 1LL * aa2[i2].first * bb2[j2].first) j2--;
            if (j2 < 0) break;
            if (s1 == 1LL * aa2[i2].first * bb2[j2].first && ans > aa1[i1].second + bb1[j1].second + aa2[i2].second + bb2[j2].second) {
                ans = aa1[i1].second + bb1[j1].second + aa2[i2].second + bb2[j2].second;
                x1 = aa1[i1].first;
                y1 = bb1[j1].first;
                x2 = aa2[i2].first;
                y2 = bb2[j2].first;
            }
        }
    }
    if (ans == INF) cout << "-1\n"; else cout << ans << "\n" << x1 << " " << y1 << "\n" << x2 << " " << y2 << "\n";
    return 0;
}