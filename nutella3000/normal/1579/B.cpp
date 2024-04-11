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
const int N = 1e5 + 3;


int n;
vector<int> a;

void sheesh(int l, int r, int d) {
    vector<int> b(n);
    copy(all(a), b.begin());
    for (int i = l; i < r; ++i) {
        int q = i + d;
        if (q >= r) q -= r - l;
        b[i] = a[q];
    }
    swap(a, b);
}


void run() {
    cin >> n;
    a.clear(); a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<pii> b;
    for (int l = 0; l < n; ++l) {
        int id = l;
        for (int i = l; i < n; ++i)
            if (a[id] > a[i]) id = i;
        if (id == l) continue;
        b.pb(l, id);
        sheesh(l, id + 1, id - l);
    }
    cout << size(b) << endl;
    for (auto i : b)
        cout << i.fi + 1 << " " << i.se + 1 << " " << i.se - i.fi << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}