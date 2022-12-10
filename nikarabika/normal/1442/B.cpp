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

const int maxn = 300 * 1000;
const LL Mod = 998244353;
int fen[maxn];

void inc(int idx) {
    for (idx++; idx < maxn; idx += idx & -idx)
        fen[idx]++;
}

int get(int idx) {
    int sum = 0;
    for (; idx; idx -= idx & -idx)
        sum += fen[idx];
    return sum;
}

int get(int st, int en) {
    return get(en) - get(st);
}

int solve() {
    int n, m;
    cin >> n >> m;
    memset(fen, 0, (n + 10) * 4);
    int na[n];
    int b[m];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x, x--;
        na[x] = i;
    }
    set<int> s;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x = na[x - 1];
        b[i] = x;
        s.insert(x);
    }
    s.insert(-1);
    s.insert(n);
    LL ans = 1;
    for (int i = 0; i < m; i++) {
        int pos = b[i];
        s.erase(pos);
        auto it = s.lower_bound(pos);
        int ri = *it;
        it--;
        int le = *it;

        int lelen = pos - le - 1;
        int lesum = get(le + 1, pos);

        int rilen = ri - pos - 1;
        int risum = get(pos + 1, ri);

        if (lelen == lesum and rilen == risum)
            return cout << 0 << '\n', 0;
        else if (lelen != lesum and rilen != risum)
            ans = ans * 2 % Mod;

        inc(b[i]);
    }
    cout << ans << '\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}