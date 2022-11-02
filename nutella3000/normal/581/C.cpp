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
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);

    int n, k;
    cin >> n >> k;
    vector<int> a(10);
    int res = 0;
    int temp = 0;
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        a[v % 10]++;
        res += v / 10;
        temp += (100 - (v + 9) / 10 * 10);
    }

    for(int i = 9;i > 0;i--) {
        int num = 10 - i;
        res += min(a[i], k / num);
        k -= min(a[i], k / num) * num;
    }
    res += min(k, temp) / 10;
    cout << res;
}