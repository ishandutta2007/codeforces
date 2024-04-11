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
mt19937 Rand(0);


const int inf = 1e9 + 7;


int c(int n, int a, int b) {
    vector<int> c;
    while (n > 0) {
        c.pb(n % 10);
        n /= 10;
    }
    int id = 0;
    while (id < size(c) && c[id] != b) ++id;
    ++id;
    while (id < size(c) && c[id] != a) ++id;
    if (id >= size(c)) return inf;
    return id - 1;
}

void run() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    int id = n - 1, sum = 0;
    while (true) {
        sum += k - a[id];
        if (sum >= k) break;
        --id;
        if (id < 0) break;
    }
    cout << n - id - 1 << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        run();
    }
}