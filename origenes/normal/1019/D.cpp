#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 2123;

struct Point {
    int x, y, idx;

    bool operator<(const Point &rhs) const{
        return mp(y, x) > mp(rhs.y, rhs.x);
    }

    Point operator+(const Point &rhs) {
        return {x + rhs.x, y + rhs.y, -idx};
    }

    Point operator-(const Point &rhs) {
        return {x - rhs.x, y - rhs.y, -idx};
    }
}pts[maxn];

ll operator*(const Point &a, const Point &b) {
    return ll(a.x) * b.y - ll(b.x) * a.y;
}

ll area(const Point &a, const Point &b, const Point &c) {
    return abs(a * b + b * c + c * a);
}

struct Seg {
    Point p;
    int idx1, idx2;
    bool operator<(const Seg &rhs) const {
        return p * rhs.p > 0;
    }
};

int n, loc[maxn];
ll s;
vector<Seg> segs;

void print(const Point &a, const Point &b, const Point &c) {
    puts("Yes");
    printf("%d %d\n%d %d\n%d %d\n", a.x, a.y, b.x, b.y, c.x, c.y);
}

bool search(int L, int R, int a, int b) {
    while (L <= R) {
        int M = (R - L >> 1) + L;
        ll now = area(pts[M], pts[a], pts[b]);
        if (now == 2 * s) {
            print(pts[M], pts[a], pts[b]);
            return true;
        }
        now > 2 * s ? L = M + 1 : R = M - 1;
    }
    return false;
}

int main() {
    scanf("%d%lld", &n, &s);
    REP(i, n) scanf("%d%d", &pts[i].x, &pts[i].y);
    sort(pts , pts + n);
    REP(i, n) pts[i].idx = loc[i] = i;
    REP(i, n) REP(j, i) segs.pb({pts[j] - pts[i], i, j});
    sort(all(segs));
    for (auto &seg : segs) {
        int &a = loc[seg.idx1], &b = loc[seg.idx2];
        if (search(0, b - 1, a, b) || search(a, n - 1, a, b)) return 0;
        swap(pts[a], pts[b]);
        swap(a, b);
    }
    puts("No");
    return 0;
}