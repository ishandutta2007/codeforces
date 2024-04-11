#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);



int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, h;
    scanf("%d%d", &n, &h);
    
    double s = (h * 1) / 2.0 / n;
    
    double cur = 1;

    vector<double> ans;
    for (int i = 0; i < n - 1; ++i) {
        double l = cur, r = 0;
        for (int j = 0; j < 100; ++j) {
            double mid = (l + r) / 2;

            if ((cur - mid) * h * (cur + mid) / 2 > s) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans.puba(l * h);
        cur = l;
    }

    sort(bend(ans));

    for (auto num : ans) {
        cout << num << " ";
    }

    cout << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}