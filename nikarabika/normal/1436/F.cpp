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

const LL Mod = 998244353;
const int maxn = 100100;

struct DS {
    LL cnt, sum, ans, sumij, sumi2;
} ds[maxn];

LL Pow(LL x, LL y) {
    LL ans = 1,
       an = x;
    while (y) {
        if (y & 1LL)
            ans = ans * an % Mod;
        an = an * an % Mod;
        y >>= 1;
    }
    return ans;
}

LL coefi2(LL x) {
    if (x <= 0) return 0;
    if (x == 1)
        return 0;
    return Pow(2, x - 2) * ((x - 1) % Mod) % Mod;
}

LL coefij(LL x) {
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    return ((x % Mod) * Pow(2, x - 3)) % Mod;
}

DS merge(DS &le, DS &ri) {
    DS res;
    res.cnt = le.cnt + ri.cnt;
    res.sum = (le.sum + ri.sum) % Mod;
    res.sumi2 = (le.sumi2 + ri.sumi2) % Mod;
    res.sumij = (le.sumij + ri.sumij + 2 * le.sum * ri.sum) % Mod;
    return res;
}

LL ansof(DS x) {
    LL ans = 0;
    ans = (x.sumi2 * coefi2(x.cnt)) % Mod;
    ans = (ans + x.sumij * coefij(x.cnt)) % Mod;
    //ans = (ans - x.sumij - x.sumi2) % Mod;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            LL fi, se;
            cin >> fi >> se;
            ds[fi].cnt = se;
            ds[fi].sum = (fi * se) % Mod;
            ds[fi].sumi2 = (fi * ds[fi].sum) % Mod;
            ds[fi].sumij = ((se * (se - 1) % Mod) * fi % Mod) * fi % Mod;
        }
    }
    for (int i = 1; i < maxn; i++)
        for (int j = i + i; j < maxn; j += i)
            ds[i] = merge(ds[i], ds[j]);
    for (int i = maxn - 1; i > 0; i--) {
        ds[i].ans = ansof(ds[i]);
        for (int j = i + i; j < maxn; j += i) {
            ds[i].ans -= ds[j].ans;
            ds[i].ans %= Mod;
        }
    }
    cout << (ds[1].ans + Mod) % Mod << '\n';
	return 0;
}