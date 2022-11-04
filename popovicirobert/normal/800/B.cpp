#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<pair<double, double>> pts(n);
    for(i = 0; i < n; i++) {
    	cin >> pts[i].first >> pts[i].second;
    }

    double ans = 1e18;
    for(i = 0; i < n; i++) {
    	double xa = pts[i].first, ya = pts[i].second;
    	double xb = pts[(i + 1) % n].first, yb = pts[(i + 1) % n].second;
    	double xc = pts[(i + 2) % n].first, yc = pts[(i + 2) % n].second;

    	double A = yc - ya, B = xa - xc, C = ya * xc - xa * yc;
    	ans = min(ans, fabs(A * xb + B * yb + C) / sqrt(A * A + B * B));
    }

    cout << fixed << setprecision(20) << ans * 0.5;
    
    return 0;
}