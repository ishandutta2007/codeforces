#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

struct point {
    int x, y;
    point(): x(), y() {}
    point(int _x, int _y): x(_x), y(_y) {}
};

int n;
point adil, bera, bin, a[N];

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (ll)(a.x - b.x) + (a.y - b.y) * (ll)(a.y - b.y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> adil.x >> adil.y >> bera.x >> bera.y >> bin.x >> bin.y;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    if (n == 1) {
        cout << fixed << setprecision(12);
        cout << min(dist(a[0], adil) + dist(a[0], bin), dist(a[0], bera) + dist(a[0], bin)) << "\n";
        return 0;
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 2 * dist(a[i], bin);
    }

    int best1 = -1, best2 = -1;
    double min1 = inf, min2 = inf;

    for (int i = 0; i < n; i++) {
        if (dist(a[i], adil) - dist(a[i], bin) < min1) {
            min2 = min1; best2 = best1;
            min1 = dist(a[i], adil) - dist(a[i], bin);
            best1 = i;
        }
        else if (dist(a[i], adil) - dist(a[i], bin) < min2) {
            min2 = dist(a[i], adil) - dist(a[i], bin);
            best2 = i;
        }
    }

    int abest1 = best1, abest2 = best2;

    best1 = best2 = -1;
    min1 = min2 = inf;

    for (int i = 0; i < n; i++) {
        if (dist(a[i], bera) - dist(a[i], bin) < min1) {
            min2 = min1; best2 = best1;
            min1 = dist(a[i], bera) - dist(a[i], bin);
            best1 = i;
        }
        else if (dist(a[i], bera) - dist(a[i], bin) < min2) {
            min2 = dist(a[i], bera) - dist(a[i], bin);
            best2 = i;
        }
    }

    int bbest1 = best1, bbest2 = best2;
    if (abest1 != bbest1)
        abest2 = abest1, bbest2 = bbest1;

    double ans = 1e18;
    ans = min(ans, sum - dist(a[abest1], bin) + dist(a[abest1], adil));
    ans = min(ans, sum - dist(a[bbest1], bin) + dist(a[bbest1], bera));

    ans = min(ans, sum - dist(a[abest1], bin) + dist(a[abest1], adil) - dist(a[bbest2], bin) + dist(a[bbest2], bera));
    ans = min(ans, sum - dist(a[bbest1], bin) + dist(a[bbest1], bera) - dist(a[abest2], bin) + dist(a[abest2], adil));

    cout << fixed << setprecision(12);
    cout << ans << "\n";
    return 0;
}