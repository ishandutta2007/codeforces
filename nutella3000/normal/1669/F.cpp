#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 500;

void run() {
    int n;
    cin >> n;
    vector<int> a(n), p(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i+1] = p[i] + a[i];
    }
    int res = 0, sum = 0;
    for (int i = n-1; i >= 0; --i) {
        sum += a[i];
        int id = lower_bound(all(p), sum) - p.begin();
        if (p[id] == sum && sum*2 <= p[n]) res = n-i + id;
    }
    cout << res << endl;
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}