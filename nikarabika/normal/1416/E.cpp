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

const LL INF = 2000LL * 1000 * 1000 * 1000000000;
set<pll> segs;
LL sign, bias;

void restart() {
    segs.clear();
    sign = +1;
    bias = 0;
    return;
}

LL convertb(LL val) {
    return (val - bias) * sign;
}

pll convertb(pll seg) {
    seg.L = convertb(seg.L);
    seg.R = convertb(seg.R);
    if (seg.L > seg.R)
        swap(seg.L, seg.R);
    return seg;
}

void add(pll seg) {
    seg = convertb(seg);
    if (seg.L == seg.R) {
        auto it = segs.lower_bound(MP(seg.L, -INF));
        if (it != segs.begin()) {
            it--;
            if (it->R >= seg.L)
                return;
        }
    }
    segs.insert(seg);
}

void tighten(pll seg) {
    seg = convertb(seg);
    while (sz(segs) and segs.begin()->L < seg.L) {
        pll badseg = *segs.begin();
        segs.erase(segs.begin());
        smax(badseg.L, seg.L);
        if (badseg.L <= badseg.R)
            segs.insert(badseg);
    }
    while (sz(segs) and segs.rbegin()->R > seg.R) {
        pll badseg = *segs.rbegin();
        segs.erase(badseg);
        smin(badseg.R, seg.R);
        if (badseg.L <= badseg.R)
            segs.insert(badseg);
    }
}

bool can_connect(pll seg) {
    if (sz(segs) == 0)
        return false;
    seg = convertb(seg);
    if (seg.R < segs.begin()->L or seg.L > segs.rbegin()->R)
        return false;
    auto it = segs.lower_bound(MP(seg.L, -INF));
    if (it != segs.end() and it->L <= seg.R)
        return true;
    if (it == segs.begin())
        return false;
    it--;
    return it->R >= seg.L;
}

int solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dp[n + 1];
    dp[n] = 0;
    restart();
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 2 == 0) {
            if (can_connect(MP(a[i] / 2, a[i] / 2))) {
                restart();
                dp[i] = dp[i + 1] + 2;
            }
            else if (can_connect(MP(1, a[i] - 1))) {
                dp[i] = dp[i + 1] + 1;
                tighten(MP(1, a[i] - 1));
            }
            else {
                restart();
                dp[i] = dp[i + 1] + 1;
            }
            add(MP(a[i] / 2, a[i] / 2));
        }
        else if (can_connect(MP(1, a[i] - 1))) {
            //cerr << "--------" << i << endl;
            dp[i] = dp[i + 1] + 1;
            tighten(MP(1, a[i] - 1));
        }
        else {
            dp[i] = dp[i + 1];
            restart();
            add(MP(1, a[i] - 1));
        }
        sign = -sign;
        bias = a[i] - bias;
        //cerr << dp[i] << ": ";
    }
    cerr << '\n';
    cout << 2 * n - dp[0] << endl;
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