#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 112345;

struct Point {
    double x, y;
} p[maxn];

int n;

bool check(double x, double r) {
    if (p[1].y < 0) r = -r;
    FOR(i, 1, n) if (sqr(p[i].x - x) + sqr(p[i].y - r) > sqr(r)) return false;
    return true;
}

double rad(double x) {
    double l = 0, r = 1e14;
    REP(i, 68) {
        double m = (l + r) / 2;
        if (check(x, m)) r = m;
        else l = m;
    }
    return l;
}

int main() {
    scanf("%d", &n);
    scanf("%lf%lf", &p[1].x, &p[1].y);
    bool flag = p[1].y > 0;
    FOR(i, 2, n) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        if ((p[i].y > 0) ^ flag) {
            puts("-1");
            return 0;
        }
    }
    double l = -1e7, r = 1e7;
    REP(_i, 76) {
        double m1 = (2 * l + r) / 3, m2 = (2 * r + l) / 3;
        if (rad(m1) < rad(m2)) r = m2;
        else l = m1;
    }
    printf("%.10lf", rad(l));
}