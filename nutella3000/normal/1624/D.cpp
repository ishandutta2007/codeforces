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
#define vvi vector<vector<int>>

mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7;
const int N = (1 << 19);

void run() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; ++i)
        ++cnt[s[i] - 'a'];
    int t = 0, c = 0;
    for (int i = 0; i < 26; ++i) {
        t += cnt[i] / 2;
        c += cnt[i] % 2;
    }
    // t/k
    // k-t%k
    int mn = 0;
    for (int i = 0; i <= t; ++i) {
        int nt = t-i, nc = c+2*i;
        int nval = 2*(nt/k);
        if (nc >= k-nt%k) ++nval;
        chkmax(mn, nval);
    }
    cout << mn << endl;
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