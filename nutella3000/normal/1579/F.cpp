#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
//#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);

const int inf = 1e9 + 7;
const int N = 2e5 + 3;


void run() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n), time(n, inf);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) time[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (time[i]) continue;
        int v = (i - d + n) % n;
        while (time[v] == inf) {
            time[v] = time[(v + d) % n] + 1;
            v = (v - d + n) % n;
        }
    }

    int mx = *max_element(all(time));
    if (mx == inf)
        cout << -1 << endl;
    else {
        cout << mx << endl;
    }
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}