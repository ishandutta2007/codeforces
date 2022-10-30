#include<bits/stdc++.h>
using namespace std;
 
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& a, int b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(int& a, int b){ if(a < b){ a = b; return 1; } return 0; }

mt19937 Rand(time(0));
int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7, mod = 998244353;
const int N = 1e6 + 3;
int n;
int c[N];
int sd[N];
vector<int> pr;

void init() {
    for (int i = 2; i < N; ++i) {
        if (!sd[i]) sd[i] = i, pr.pb(i);
        for (int j : pr) {
            if (j > sd[i] || j*i >= N) break;
            sd[i*j] = j;
        }
    }
}

vector<pii> fac(int a) {
    vector<pii> res;
    while (a > 1) {
        int val = sd[a], c = 0;
        while (sd[a] == val) a /= sd[a], ++c;
        res.pb(val, c);
    }
    return res;
}

vector<int> del(int a) {
    auto b = fac(a);
    vector<int> res{1};
    for (auto &[p, c] : b) {
        int sz = size(res);
        int pi = 1;
        for (int i = 1; i <= c; ++i) {
            pi *= p;
            for (int j = 0; j < sz; ++j)
                res.pb(res[j]*pi);
        }
    }
    return res;
}

void run() {
    init();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        auto ds = del(a);
        for (int d : ds)
            ++c[d];
    }
    int res = 0;
    for (int i = 1; i < N; ++i) {
        if (!c[i]) continue;
        bool bad = false;
        for (int j = 2*i; j < N; j += i) {
            if (c[j] == c[i]) bad = true;
        }
        res += !bad;
    }
    cout << res - n << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}