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
const int N = 4e5 + 3;

int n, d;
int par[N], sz[N], mx_sz = 1, dead[N];

int get(int v) { return par[v] == v ? v : par[v] = get(par[v]); }

int merge(int v1, int v2) {
    v1 = get(v1);
    v2 = get(v2);
    if (v1 == v2) return 0;
    sz[v1] += sz[v2];
    dead[v2] = true;
    chkmax(mx_sz, sz[v1]);
    par[v2] = v1;
    return 1;
}

void run() {
    cin >> n >> d;
    iota(par, par + N, 0);
    fill(sz, sz + N, 1);

    int c = 0;
    for (int i = 0; i < d; ++i) {
        int v1, v2;
        cin >> v1 >> v2; --v1, --v2;
        c += merge(v1, v2);
        int kal = (i + 1 - c);
        vector<int> ab;
        for (int j = 0; j < n; ++j) {
            if (!dead[j]) ab.pb(sz[j]);
        }
        sort(all(ab));
        int res = 0;
        for (int i = 0; i < kal + 1; ++i)
            res += ab[size(ab) - i - 1];
        cout << res - 1 << endl;
    }
}



signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}