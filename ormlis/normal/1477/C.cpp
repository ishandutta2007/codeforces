#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;

struct pt {
    ll x = 0, y = 0;
};

pt rotate(const pt &a) {
    return {-a.y, a.x};
}

bool operator<(const pt &a, const pt &b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}

bool operator==(const pt &a, const pt &b) {
    return a.x == b.x && a.y == b.y;
}

pt operator*(const pt &a, const ll &b) {
    return {a.x * b, a.y * b};
}

pt operator/(const pt &a, const ll &b) {
    return {a.x / b, a.y / b};
}

pt operator+(const pt &a, const pt &b) {
    return {a.x + b.x, a.y + b.y};
}

pt operator-(const pt &a, const pt &b) {
    return {a.x - b.x, a.y - b.y};
}

// - 
ll operator*(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

//
ll operator%(const pt &a, const pt &b) {
    return a.x * b.x + a.y * b.y;
}

vector<pt> ConvexHull(vector<pt> pts) {
    int min_idx = min_element(all(pts)) - pts.begin();
    swap(pts[0], pts[min_idx]);

    sort(pts.begin() + 1, pts.end(), [&](const pt &a, const pt &b) {
        ll z = (a - pts[0]) * (b - pts[0]);
        if (z) return z > 0;
        return (a - pts[0]) % (a - pts[0]) < (b - pts[0]) % (b - pts[0]);
    });

    vector<pt> convex_hull = {pts[0]};
    int sz = 0;
    for (int i = 1; i < (int) pts.size(); ++i) {
        while (sz && (convex_hull[sz] - convex_hull[sz - 1]) * (pts[i] - convex_hull[sz]) <= 0) {
            convex_hull.pop_back();
            --sz;
        }
        convex_hull.push_back(pts[i]);
        ++sz;
    }
    return convex_hull;
}

vector<pair<pt, int>> pts;
int n;
vector<int> answer;
bool check(pt x) {
    n = pts.size();
    if (n == 1) {
        answer.push_back(pts[0].second);
        return true;
    }
    vector<pt> pt2(n);
    range(i, n) pt2[i] = pts[i].first;
    auto ch = ConvexHull(pt2);
    pt ans = {-INF, -INF};
    range(i, (int)ch.size()) {
        pt V = x - ch[i];
        pt V2 = ch[(i-1+(int)ch.size()) % (int)ch.size()] - ch[i];
        pt V3 = ch[(i+1)%(int)ch.size()] - ch[i];
        if (V % V2 <= 0) continue;
        if (V % V3 <= 0) continue;
        ans = ch[i];
        break;
    }
    if (ans.x == -INF) return false;
    range(i, n) {
        if (pts[i].first == ans) {
            answer.push_back(pts[i].second);
            pts.erase(pts.begin() + i);
            break;
        }
    }
    return check(ans);
}

void solve() {
    cin >> n;
    pts.resize(n);
    range(i, n) {
        cin >> pts[i].first.x >> pts[i].first.y;
        pts[i].second = i;
    }
    int min_idx = min_element(all(pts)) - pts.begin();
    pt x = pts[min_idx].first;
    answer.push_back(pts[min_idx].second);
    pts.erase(pts.begin() + min_idx);
    if (check(x)) {
        range(i, answer.size()) cout << answer[i] + 1 << ' ';
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}