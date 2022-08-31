#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

double angle (int x, int y) {
    if (y == 0 and x > 0) return 0;
    else if (y == 0 and x < 0) return 180;

    if (x == 0 and y > 0) return 90;
    else if (x == 0 and y < 0) return 270;

    double ans = (atan((double)abs(y) / abs(x)) * 180 ) / (4 * atan(1.0));

    if (x > 0 and y > 0) return ans;
    else if (x < 0 and y > 0) return 180 - ans;
    else if (x < 0 and y < 0) return 180 + ans;
    return 360 - ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<double, pi>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].second.first >> a[i].second.second;

    for (int i = 0; i < n; i++) {
        int x = a[i].second.first, y = a[i].second.second;
        a[i].first = angle(x, y);
    }

    sort(all(a));

    double max_angle = INT_MIN;
    for (int i = 1; i < n; i++) {
        max_angle = max(max_angle, a[i].first - a[i-1].first);
    }

    cout << setprecision(10);
    cout << min(a[n-1].first - a[0].first, 360 - max_angle) << "\n";
    return 0;
}