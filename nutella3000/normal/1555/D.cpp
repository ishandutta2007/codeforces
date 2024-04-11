#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
const int max_n = 2e5 + 4;

int cnt[max_n][3];

int c(int l, int r, int ost, int let) {
    int tl = l - l % 3 + ost;
    int tr = r - r % 3 + ost;
    if (tl >= l) tl -= 3;
    if (tr >= r) tr -= 3;
    return (tr >= 0 ? cnt[tr][let] : 0) - (tl >= 0 ? cnt[tl][let] : 0);
}

void run() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    for (int i = 0; i < n; ++i) {
        cnt[i][s[i] - 'a'] = 1;
        for (int j = 0; j < 3; ++j)
            if (i >= 3) cnt[i][j] += cnt[i - 3][j];
    }
    string alp = "abc";
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l;

        int res = inf;
        do {
            int nres = 0;  
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    if (alp[i] - 'a' != j) nres += c(l, r, i, j);
            chkmin(res, nres);
        } while(next_permutation(all(alp)));
        cout << res << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}