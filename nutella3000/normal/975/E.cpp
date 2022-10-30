#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const ld PI = cos(0), eps = 1e-6;
const int max_n = 1e4 + 5;

bool eq(ld a, ld b) {
    return fabsl(a - b) < eps;
}

bool ls(ld a, ld b) {
    return a < b && !eq(a, b);
}

bool lseq(ld a, ld b) {
    return a < b || eq(a, b);
}

struct Point {
    ld x, y;

    Point() : x(), y() {}

    Point(ld x, ld y) : x(x), y(y) {}

    Point operator + (const Point& a) const {
        return Point(x + a.x, y + a.y);
    }

    Point operator - (const Point& a) const {
        return Point(x - a.x, y - a.y);
    }

    Point operator * (const ld k) const {
        return Point(x * k, y * k);
    }

    Point operator / (const ld k) const {
        return Point(x / k, y / k);
    }

    ld operator % (const Point& a) const {
        return x * a.x + y * a.y;
    }

    ld operator * (const Point& a) const {
        return x * a.y - y * a.x;
    }

    ld len() const {
        return sqrt(*this % *this);
    }

    Point ort() const {
        return Point(-y, x);
    }

    Point norm() const {
        return *this / len();
    }

    Point rot(const ld ca, const ld sa) const {
        return *this * ca + ort() * sa;
    }

    Point rot(const ld ang) const {
        return rot(cos(ang), sin(ang));
    }
};


ld angle(Point a, Point b) {
    ld res = acos(a % b / a.len() / b.len());
    if (ls(a * b, 0)) res = -res;
    return res;
}

ld square(Point a, Point b) {
    return a * b / 2;
}

int n, q;
Point st[max_n];
Point c;

Point find_centroid(Point a, Point b) {
    return (a + b) / 3;
}

Point find_centroid() {
    Point res;
    ld sum = 0;
    for(int i = 0;i < n;i++) {
        int ne = (i + 1) % n;
        ld mass = square(st[i], st[ne]);
        sum += mass;
        res = res + find_centroid(st[i], st[ne]) * mass;
    }

    res = res / sum;

    return res;
}

void scan() {
    cin >> n >> q;
    for(int i = 0;i < n;i++) 
        cin >> st[i].x >> st[i].y;

    Point d = st[0];
    for(int i = 0;i < n;i++)
        st[i] = st[i] - d;

    c = find_centroid() + d;

    for(int i = 0;i < n;i++) 
        st[i] = st[i] - c + d;
}

ld ang = 0;

Point fisting(int v) {
    return st[v].rot(ang) + c;
}

void solve() {
    scan();

    int ver[]{0, 1};


    while(q--) {
        int que;
        cin >> que;
        if (que == 1) {
            int f, t;
            cin >> f >> t;
            f--; t--;
            int d = (ver[0] == f ? 0 : 1);
            ver[d] = t;
            d = ver[1 - d];

            //cout << st[d].x << " " << st[d].y << endl;

            c = fisting(d);
            c.y -= st[d].len();

            ang = angle(st[d], Point(0, 1));

            //cout << "centroid: " << c.x << " " << c.y << endl;
        }else {
            int v;
            cin >> v;
            v--;

            Point res = fisting(v);
            cout << (double)res.x << " " << (double)res.y << endl;
        }
    }
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}