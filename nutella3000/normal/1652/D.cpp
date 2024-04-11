#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair
#define siz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb emplace_back
#define pii pair<int, int>
#define chmax(a, b) a = max(a, b)

const int N = 2e5 + 3, mod = 998244353;

int sum(int a, int b) { int r = a+b; if (r >= mod) r -= mod; return r; }
void add(int& a, int b) { a += b; if (a >= mod) a -= mod; }
int mul(int a, int b) { return a*b % mod; }
int binpow(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = mul(a, a))
        if (b & 1) r = mul(r, a);
    return r;
}
int inv(int a) { return binpow(a, mod - 2); }

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

vector<int> pr;
vector<int> ids[N];


int n;
vector<pair<int, pii>> gr[N];
vector<int> one;


void dfs1(int v, vector<int>& two, int p = -1) {
    for (auto id : gr[v]) {
        int to = id.fi, x = id.se.fi, y = id.se.se;
        if (to == p) continue;

        for (int i : ids[x])
            --two[i];
        for (int i : ids[y]) {
            ++two[i];
            chmax(one[i], two[i]);
        }
        dfs1(to, two, v);
        for (int i : ids[x])
            ++two[i];
        for (int i : ids[y])
            --two[i];
    }
}

int res = 0;
void dfs2(int v, int vx, int p = -1) {
    add(res, vx);
    for (auto id : gr[v]) {
        int to = id.fi, x = id.se.fi, y = id.se.se;
        if (to == p) continue;
        dfs2(to, mul(vx, mul(x, inv(y))), v);
    }
}

void run() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        gr[i].clear();
    one.clear();
    one.resize(n+1, 0);

    for (int i = 0; i < n-1; ++i) {
        int v1, v2, x, y; cin >> v1 >> v2 >> x >> y; --v1, --v2;
        //int g = gcd(x, y); x /= g, y /= g;
        gr[v2].pb(v1, mp(x, y));
        gr[v1].pb(v2, mp(y, x));
    }
    vector<int> two(n+1);
    dfs1(0, two);

    /*for (int i = 0; i <= n; ++i)
        cout << one[i] << " ";
    cout << endl;*/
    int t = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < one[i]; ++j) {
            t = mul(t, pr[i]);
        }
    }
    res = 0;
    dfs2(0, t);
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    for (int _n = 2; _n <= 2e5; ++_n) {
        int n = _n;
        bool bad = false;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                bad = true;
                ids[_n].pb(i);
                n /= i;
            }
        }
        if (!bad) pr.pb(n);
        if (n != 1) ids[_n].pb(n);

        for (int& i : ids[_n])
            i = lower_bound(all(pr), i) - pr.begin();
    }

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}