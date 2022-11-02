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
const int N = 1e5 + 3, M = 2e7 + 3;

int n;
int cnt[M], dp[M];
int mind[M];
vector<int> pr;

void rec(int x) {
    vector<int> div = {1};
    ++cnt[1];
    while (x > 1) {
        int p = mind[x], sz = size(div);
        for (int i = 1, pw = p; !(x % p); ++i, pw *= p, x /= p) {
            for (int j = 0; j < sz; j++) {
                int tmp = div[j] * pw;
                div.emplace_back(tmp);
                ++cnt[tmp];
            }
        }
    }
}

void run() {
    for (int i = 2; i < M; ++i) {
        if (!mind[i]) mind[i] = i, pr.pb(i);
        for (int j : pr) {
            if (i * j >= M || j > mind[i]) break; // 
            mind[i*j] = j;
        }
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v; rec(v);
    }

    for (int i = 1; i < M; ++i) {
        dp[i] += cnt[i] * i;
        for (int j : pr) {
            int val = i * j;
            if (val >= M) break;
            chkmax(dp[val], dp[i] - i * cnt[val]);
        }
    }
    int res = 0;
    for (int i = 1; i < M; ++i)
        chkmax(res, dp[i]);
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);

    auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }

    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}