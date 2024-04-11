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
const int N = 2e5 + 3;

void run() {
    int n, l;
    cin >> n >> l;
    vector<int> x(n);
    vector<int> cnt(l);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        for (int j = 0; j < l; ++j) {
            if (x[i] >> j & 1) ++cnt[j];
        }
    }
    int y = 0;
    for (int i = 0; i < l; ++i) {
        if (cnt[i] > n/2) y += (1 << i);
    }
    cout << y << endl;
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