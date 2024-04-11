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
#define ld long double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }

const int inf = 1e9 + 7;

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0, id = 0;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int v = a[i];
        while (v % 2 == 0)
            v /= 2, ++c;
        if (v > mx) {
            mx = v;
            id = i;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int v = a[i];
        while (v % 2 == 0)
            v /= 2;
        if (i == id) {
            for (int j = 0; j < c; ++j)
                v *= 2;
        }
        res += v;
    }
    cout << res << endl;
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}