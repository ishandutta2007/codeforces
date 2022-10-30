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
 
 
const int inf = 1e15 + 7;
const int N = 1e6 + 3;


void run() {
    int n, q; cin >> n >> q;
    vector<int> a(n), t(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int al = -1, al_t = -1;

    for (int it = 1; it <= q; ++it) {
        int ty, id, x; cin >> ty;
        if (ty == 1) {
            cin >> id >> x; --id;
            
            if (t[id] > al_t) sum -= a[id];
            else sum -= al;

            t[id] = it;
            a[id] = x;
            sum += x;
        } else {
            cin >> x;
            sum = n*x;
            al = x, al_t = it;
        }
        cout << sum << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}