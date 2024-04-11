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
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e16; 

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n, k;
    cin >> n >> k;
    vector<int> cnt(k + 1);
    int res = 0;
    for(int i = 0;i < n;i++) {
        int d;
        cin >> d;
        cnt[d % k]++;
    }
    for(int i = 0;i <= k / 2;i++) {
        if (i * 2 == k || i == 0) res += cnt[i] / 2;
        else res += min(cnt[i], cnt[k - i]);
    }
    cout << 2 * res;
}