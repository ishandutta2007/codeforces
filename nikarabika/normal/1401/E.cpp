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

const int maxn = 1000 * 1000 + 10;
int fen[maxn];
vector<pii> vers[maxn],
    hors[maxn];

void inc(int idx, int val) {
    for (idx++; idx < maxn; idx += idx & -idx)
        fen[idx] += val;
}

int get(int idx) {
    int ans;
    for (ans = 0; idx; idx -= idx & -idx)
        ans += fen[idx];
    return ans;
}

int get(int st, int en) {
    return get(en) - get(st);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        hors[fi].PB(MP(se, th));
    }
    for (int i = 0; i < m; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        vers[se].PB(MP(fi, +1));
        vers[th + 1].PB(MP(fi, -1));
    }
    hors[0].PB(MP(0, 1000 * 1000));
    hors[1000 * 1000].PB(MP(0, 1000 * 1000));
    vers[0].PB(MP(0, +1));
    vers[0].PB(MP(1000 * 1000, +1));
    vers[1000 * 1000 + 1].PB(MP(0, -1));
    vers[1000 * 1000 + 1].PB(MP(1000 * 1000, -1));
    LL e = 0,
       v = 0;
    for (int i = 0; i < maxn; i++) {
        for (auto quer: vers[i]) {
            v++;
            e++;
            inc(quer.L, quer.R);
        }
        for (auto quer: hors[i]) {
            int cnt = get(quer.L, quer.R + 1);
            v += cnt + 2;
            e += 4 * cnt + 2;
        }
    }
    e /= 2;
    cout << e - v + 1 << '\n';
	return 0;
}