#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;
const int max_n = 1e5 + 3;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int h, m, H, D, c, n;
    cin >> h >> m >> H >> D >> c >> n;
    double r1 = ((H + n - 1) / n * c);
    int num = max(0ll, (20 - h - 1) * 60 + (60 - m));
    //cout << num << endl;
    double r2 = (H + num * D + n - 1) / n * (c * 0.8);
    cout << min(r1, r2) << endl;
}