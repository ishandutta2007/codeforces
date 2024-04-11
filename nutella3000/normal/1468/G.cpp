#include <bits/stdc++.h>
        
using namespace std;
        
mt19937 rnd(time(0));
        
//        //\\      ||||||  ||||          //\\        ||||||
//       //  \\       ||    ||  ||       //  \\       ||   ||
//      //    \\      ||    ||   ||     //    \\      ||   ||
//     //------\\     ||    ||   ||    //------\\     ||||||
//    //        \\    ||    ||   ||   //        \\    ||  \\
//   //          \\ ||||||  |||||    //          \\   ||   \\
        
#define AIDAR ASADULLIN
        
#define int long long
#define mp make_pair
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define double long double
#define size(a) (int)(a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
 
const int inf = 1e9;
const int max_n = 2e5 + 3;
const double eps = 1e-9;

int sign(double a) { return a < -eps ? -1 : a > eps; }

struct P {
    double x, y;

    P() : x(), y() {}
    P(double x, double y) : x(x), y(y) {}

    P operator+ (P a) { return {x + a.x, y + a.y}; }
    P operator- (P a) { return {x - a.x, y - a.y}; }
    P operator* (double a) { return {x * a, y * a}; }
    P operator/ (double a) { return {x / a, y / a}; }

    double abs() { return sqrt(x * x + y * y); }

    double dist(P a) { return (a - *this).abs(); }

    double det(P a) { return x * a.y - y * a.x; }
};

#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x))

P intersect(P p1, P p2, P q1, P q2) {
    double a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return (p1 * a2 + p2 * a1) / (a1 + a2);
}

void solve() {
    int n, h;
    cin >> n >> h;
    vector<P> a(n);
    for(int i = 0;i < n;i++) {
        int x, y;
        cin >> x >> y;
        a[i] = P(x, y);
    }
    P eye = P(a[n - 1].x, a[n - 1].y + h);
    P bor = a[n - 1];

    double res = 0;

    for(int i = n - 2;i >= 0;i--) {
        if (sign(cross(bor, eye, a[i])) >= 0) {
            if (sign(cross(bor, eye, a[i + 1])) >= 0) res += a[i].dist(a[i + 1]);
            else res += a[i].dist(intersect(eye, bor, a[i], a[i + 1]));
            bor = a[i];
        }
    }

    cout << res << endl;
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(15);
        
#ifdef technocum
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
}