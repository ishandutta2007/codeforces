// Not my code
// https://codeforces.com/contest/195/submission/90708559
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
const int N = 200005;
const long double EPS = 0;
const long long INF = 1E20;
 
int n, b, k;
long long cur = 0;
int ans = 0;
vector<pair<long double, int>> ve;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k >> b;
        if (k == 0) {
            continue;
        }
        long double pos = (long double)-b / k;
        if (k < 0) {
            ve.push_back({pos, -k});
        } else {
            ve.push_back({pos, k});
        }
    }
    sort(ve.begin(), ve.end());
    ve.push_back({INF, 0});
    for (int i = 0; i < ve.size() - 1; i++) {
        cur += ve[i].se;
        if (abs(ve[i].fi - ve[i + 1].fi) > EPS) {
            ans += (cur != 0);
            cur = 0;
        }
    }
    cout << ans;
}