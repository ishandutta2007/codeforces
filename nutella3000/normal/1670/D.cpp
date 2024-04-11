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
const int N = (1 << 10), mod = 1e9 + 7;

void run() {
    int n; cin >> n;
    int l = -1, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int a = mid/3;
        int b = (mid+1)/3;
        int c = (mid+2)/3;
        if (2*(a*b + b*c + c*a) >= n) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}