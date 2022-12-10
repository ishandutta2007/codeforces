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

pii maxel(set<pii> &s) {
    auto it = s.end();
    it--;
    return *it;
}

int solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int c = n + 1;
    int a[n];
    int cnt[c];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    int nused = find(cnt, cnt + c, 0) - cnt;
    set<pii> s;
    for (int i = 0; i < c; i++)
        if (cnt[i])
            s.insert(MP(cnt[i], i));
    int b[n];
    int mcnt[c];
    memset(b, -1, sizeof b);
    memset(mcnt, 0, sizeof mcnt);
    for (int rem = 0; rem <= n; rem++) {
        pii mx = maxel(s);
        if (mx.L <= n - rem - mx.L and x <= rem and rem <= x + n - y) {
            int bmcnt[c];
            memset(bmcnt, 0, sizeof bmcnt);
            vector<pii> nmatch;
            for (int i = 0; i < n; i++)
                if (bmcnt[a[i]] < mcnt[a[i]]) {
                    b[i] = a[i];
                    bmcnt[a[i]]++;
                }
                else
                    nmatch.PB(MP(a[i], i));
            sort(all(nmatch));
            for (int i = 0; i < sz(nmatch); i++) {
                int j = (i + sz(nmatch) / 2) % sz(nmatch);
                b[nmatch[i].R] = nmatch[j].L;
            }
            int badmat = rem - x;
            int baddif = n - y - badmat;
            for (int i = 0; i < n; i++)
                if (a[i] == b[i] and badmat) {
                    b[i] = nused;
                    badmat--;
                }
                else if (a[i] != b[i] and baddif) {
                    b[i] = nused;
                    baddif--;
                }
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << b[i] + 1 << ' ';
            cout << '\n';
            return 0;
        }
        s.erase(mx);
        mx.L--;
        mcnt[mx.R]++;
        s.insert(mx);
    }
    cout << "NO\n";
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