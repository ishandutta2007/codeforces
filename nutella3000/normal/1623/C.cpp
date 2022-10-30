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


void run() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    int l = -1, r = 1e9 + 3;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<int> b;
        copy(all(h), back_inserter(b));
        bool bad = false;
        for (int i = n - 1; i >= 2; --i) {
            if (b[i] < mid) bad = true;
            int d = min(b[i] - mid, h[i]) / 3;
            b[i-1] += d;
            b[i-2] += 2*d;
        }
        if (b[1] < mid || b[0] < mid || bad) r = mid;
        else l = mid;
    }
    cout << l << endl;
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