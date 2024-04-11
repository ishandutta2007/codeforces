//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2000 + 10;
const LL Mod = 1000 * 1000 * 1000 + 7;
LL c[maxn][maxn];
LL n, x, pos;
LL lt, gt;

LL comb(LL n, LL r) {
    return r < 0 or r > n ? 0 : c[n][r];
}

LL fact(LL n) {
    LL ans = 1;
    while (n > 0) {
        ans = (ans * n) % Mod;
        n--;
    }
    return ans;
}

void go(int l = 0, int r = n) {
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (mid == pos)
        go(mid + 1, r);
    else if (pos < mid) {
        gt++;
        go(l, mid);
    }
    else {
        lt++;
        go(mid + 1, r);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    c[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
        c[i][0] = 1;
        for (int j = 1; j < maxn; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % Mod;
    }
    cin >> n >> x >> pos;
    go();
    LL less = comb(x - 1, lt) * fact(lt) % Mod;
    LL more = comb(n - x, gt) * fact(gt) % Mod;
    LL oth = fact(n - lt - gt - 1);
    cout << (less * more % Mod) * oth % Mod << endl;
	return 0;
}