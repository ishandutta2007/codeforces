#include<bits/stdc++.h>
using namespace std;
 
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& a, int b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(int& a, int b){ if(a < b){ a = b; return 1; } return 0; }

mt19937 Rand(time(0));
int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7, mod = 1e9 + 7;
const int N = 1504;

int f(int a) {
    if (a == 0) return 1;
    int bit = 31 - __builtin_clz(a);
    if ((1<<bit) == a) return 0;
    return (1<<(bit+1))-a;
}

void run() {
    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(all(b));
    vector<int> a;
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        if (i == n || b[i] != b[i-1]) {
            a.pb(cnt); cnt = 1;
        } else ++cnt;
    }
    int res = inf;
    for (int k1 = 1; k1 <= n; k1 *= 2) {
        int c1 = 0;
        for (int i = 0; i < size(a); ++i) {
            if (c1 + a[i] > k1) break;
            c1 += a[i];
        }
        for (int k2 = 1; k2 <= n; k2 *= 2) {
            int c2 = 0;
            for (int i = size(a)-1; i >= 0; --i) {
                if (c2 + a[i] > k2 || c1 + c2 + a[i] > n) break;
                c2 += a[i];
            }
            int nr = (k1-c1) + (k2-c2) + f(n-c1-c2);
            chmin(res, nr);
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}