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

bool g(vector<int> a, int x) {
    int n = size(a);
    for (int i = 0, id = n - 1; i < n; ++i) {
        if (a[i] == x) continue;
        while (id >= 0 && a[id] == x) --id;
        if (a[i] != a[id]) return false;
        --id;
    }
    return true;
}

int binpow(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = a * a % inf)
        if (b & 1) r = r * a % inf;
    return r;
}
void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    int res = inf;
    for (int st = 0; st < n; ++st) {
        int lst = a[st], d = 0, cnt = 0;
        for (int it = 0; it < 33; ++it) {
            int l = -1, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (a[mid] - lst < max(d, 1ll)) l = mid;
                else r = mid;
            }
            if (d == 0) cnt += r - st;
            if (r == n) break;
            ++cnt;
            d = a[r] - a[st];
            lst = a[r];
        }
        chkmin(res, n - cnt);
    }

    cout << res << endl;
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}