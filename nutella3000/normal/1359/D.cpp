#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int max_n = 1e5 + 1;

int n;
int a[max_n];

int sum(int l, int r) {
    int res = 0, sum = 0;
    for(int i = l;i <= r;i++) {
        sum += a[i];
        sum = max(0ll, sum);
        res = max(res, sum);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) 
        cin >> a[i];

    int res = 0;
    for(int num = 30;num >= 0;num--) {
        int new_res = 0;
        int l = 0;
        for(int r = 0;r <= n;r++) {
            if (r == n || a[r] > num) {
                new_res = max(new_res, sum(l, r - 1)); 
                l = r + 1;
            }
        }
        res = max(res, new_res - num);
    }

    cout << res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}