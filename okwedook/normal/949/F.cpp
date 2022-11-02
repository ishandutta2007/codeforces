#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

constexpr int MAXC = 1000 * 1000;
const long double eps = 1e-13;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0)
        : x(x)
        , y(y)
    {
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    ll operator*(const Point& other) const {
        return ll(x) * other.y - ll(y) * other.x;
    }

    ll operator^(const Point& other) const {
        return ll(x) * other.x + ll(y) * other.y;
    }

    void norm() {
        if (make_pair(-x, -y) < make_pair(x, y)) {
            x = -x;
            y = -y;
        }
    }

    ll ang() {
        if (x == 0) return ll(MAXC) * MAXC * MAXC + 13;
        return ll(1.0 * y / x * MAXC * MAXC);
    }
};

bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool onLine(const Point& a, const Point& b, const Point& c) {
    return (b - a) * (c - a) == 0;
}

bool operator<(const Point& lhs, const Point& rhs) {
    return lhs * rhs > 0;
}

const Point BAD(MAXC + 1, MAXC + 1);
const int MX = 5207;

struct Line {
    ll a, b, c;

    Line(const Point& A, const Point& B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(A.x * a + A.y * b);
    }
};

ll det(ll a, ll b, ll c, ll d) {
    return a * d - b * c;
}

Point intersect(const Line& a, const Line& b) {
    ll dx = det(-a.c, a.b, -b.c, b.b);
    ll dy = det(a.a, -a.c, b.a, -b.c);
    ll d = det(a.a, a.b, b.a, b.b);
    if (d == 0) {
        return BAD;
    }
    if (dx % d != 0 || dy % d != 0) {
        return BAD;
    }
    Point ans(dx / d, dy / d);
    if (ans.x > MAXC || ans.x < -MAXC || ans.y > MAXC || ans.y < -MAXC) {
        return BAD;
    }
    return ans;
}

Point P[MX];

int used[MX];
int match[MX];

int lptr = 0;
pair<ll, int> lines[MX][MX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    srand(42123);

    int n;
    cin >> n;
    n *= 2;
    set<pair<ll, ll> > spts;
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
        spts.emplace(P[i].x, P[i].y);
    }

    random_shuffle(P, P + n);

    for (int i = 0; i < n; i++) {
        int ptr = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto vec = P[j] - P[i];
            vec.norm();
            lines[i][ptr++] = {vec.ang(), j};
        }
        sort(lines[i], lines[i] + n - 1);
    }

    int a = 0;
    int iter = 0;
    for (int b = 0; b < n; b++) {
        int c = 1;
        if (b == c) c++;
        for (int d = 0; d < n; d++) {
            if (d == a || d == b || d == c) continue;
            Point O = intersect(Line(P[a], P[b]), Line(P[c], P[d]));
            if (O == BAD) {
                continue;
            }
            if (spts.count({O.x, O.y})) {
                continue;
            }
            iter++;
            used[a] = used[b] = used[c] = used[d] = iter;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (used[i] == iter) continue;
                Point vec = P[i] - O;
                vec.norm();

                int pos = lower_bound(lines[i], lines[i] + n - 1, make_pair(vec.ang(), -1)) - lines[i];
                if (pos == n) {
                    ok = false;
                    break;
                }

                int v = lines[i][pos].second;

                if (!onLine(P[i], O, P[v])) {
                    ok = false;
                    break;
                }

                if (used[v] == iter) {
                    ok = false;
                    break;
                }

                used[v] = iter;
                used[i] = iter;
            }

            if (ok) {
                cout << "Yes" << endl;
                cout << O.x << " " << O.y << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}