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
const int N = 1 << 20, mod = 1e9 + 7;

vector<int> fen;

void add(int x, int y) {
    for (++x; x < siz(fen); x += x&-x)
        fen[x] += y;
}
int get(int x) {
    int res = 0;
    for (++x; x; x -= x&-x)
        res += fen[x];
    return res;
}

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
    }
    fen.assign(n+1, 0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += i - get(a[i]-1);
        add(a[i], 1);
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}