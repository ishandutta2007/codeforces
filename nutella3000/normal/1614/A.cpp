#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7;
const int N = 1e5 + 3, M = 2e7 + 3;

void run() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> a(n);
    int res = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        if (a[i] < l || a[i] > r) continue;
        if (a[i] > k) continue;
        ++res;
        k -= a[i];
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);

    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }

    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}