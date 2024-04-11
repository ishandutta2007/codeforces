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

const int maxn = 100 * 1000 + 10,
      maxsq = 320,
      maxl = 17;
set<int> s;
vector<int> vec[maxn];
vector<pii> quers;
bool mark[maxn];
int a[maxn],
    cnt[maxn],
    fen[maxn],
    n;
int imex = -1;

void inc(int idx, int val) {
    for (idx++; idx < maxn; idx += idx & -idx)
        fen[idx] += val;
}

void add(int x) {
    if (cnt[x] == 0)
        inc(x, +1);
    cnt[x]++;
}

void remove(int x) {
    cnt[x]--;
    if (cnt[x] == 0)
        inc(x, -1);
}

int mex() {
    int ans = 0;
    for (int i = maxl - 1; i >= 0; i--)
        if (fen[ans + (1 << i)] == (1 << i))
            ans += 1 << i;
    return ans;
}

bool mocmp(pii le, pii ri) {
    if (le.L / maxsq != ri.L / maxsq)
        return le.L < ri.L;
    if ((le.L / maxsq) & 1)
        return le.R < ri.R;
    return le.R > ri.R;
}

void PB(pii seg) {
    if (seg.L < seg.R)
        quers.PB(seg);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n + 5; i++) {
        vec[i].PB(-1);
        s.insert(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        PB(MP(vec[a[i]].back() + 1, i));
        vec[a[i]].PB(i);
    }
    for (int i = 0; i < n; i++)
        PB(MP(vec[i].back() + 1, n));
    PB(MP(0, n));
    sort(all(quers), mocmp);
    int l = 0, r = 0;
    for (auto qseg: quers) {
        while (l > qseg.L) {
            --l;
            add(a[l]);
        }
        while (r < qseg.R) {
            add(a[r]);
            r++;
        }
        while (l < qseg.L) {
            remove(a[l]);
            l++;
        }
        while (r > qseg.R) {
            --r;
            remove(a[r]);
        }
        mark[mex()] = true;
    }
    for (int i = 0; i < maxn; i++)
        if (!mark[i])
            return cout << i + 1 << '\n', 0;
    assert(0);
	return 0;
}