#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int n, cur[MAXN];
string a, b;

void solve(){
    cin >> n >> a >> b, --n, assert(sz(a) == n), assert(sz(b) == n);
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        auto flip = [&](char c) -> char {
            if (c == 'N') return 'S';
            if (c == 'S') return 'N';
            if (c == 'E') return 'W';
            if (c == 'W') return 'E';
            assert(false);
        };
        a[i] = flip(a[i]);
    }
    for (int p1 = 1, p2 = 0; p1 < n; cur[++p1] = p2) {
        while (p2 != 0 && b[p1] != b[p2]) p2 = cur[p2];
        p2 += b[p1] == b[p2];
    }
    int ans=0;
    for (int i = 0; i < n; i++) {
        for (; ans && a[i] != b[ans]; ans = cur[ans]);
        ans += a[i] == b[ans];
    }
    cout << (!ans?yes:no);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}