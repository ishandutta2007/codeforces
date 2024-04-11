#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll P = 239179;
const ll Q = 1000 * 1000 * 1000 + 9;

const int MX = 200 * 1000 + 7;
ll p[MX];
int lst[MX];
int a[MX];
int nxt[MX];
ll pw[MX];
int b[MX];

int any[MX];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    pw[0] = 1;
    for (int i = 1; i < MX; i++) {
        pw[i] = (pw[i - 1] * P) % Q;
    }
    string s, t;
    cin >> s >> t;
    const int NONE = n + 7;

    s = "$" + s;
    t = "$" + t;
    for (int i = 1; i <= n; i++) {
        if (lst[(int)s[i]] == 0) {
            a[i] = NONE;
        } else {
            a[i] = i - lst[(int)s[i]];
        }
        lst[(int)s[i]] = i;
    }

    memset(lst, 0, sizeof(lst));
    for (int i = n; i >= 1; i--) {
        if (lst[(int)s[i]] == 0) {
            nxt[i] = NONE;
        } else {
            nxt[i] = lst[(int)s[i]];
        }
        lst[(int)s[i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        any[(int)t[i]] = i;
    }
    memset(lst, 0, sizeof(lst));
    ll want = 0;
    for (int i = 1; i <= m; i++) {
        if (lst[(int)t[i]] == 0) {
            want = (want + pw[m - i] * NONE) % Q;
        } else {
            want = (want + pw[m - i] * (i - lst[(int)t[i]])) % Q;
        }
        lst[(int)t[i]] = i;
    }

    vector<int> ans;
    ll hs = 0;
    for (int i = 1; i <= m; i++) {
        hs = (hs + pw[m - i] * a[i]) % Q;
    }

    for (int i = 1; i + m - 1 <= n; i++) {
        if (hs == want) {
            bool ok = true;
            vector<int> go(26, -1);
            for (char c = 'a'; c <= 'z'; c++) {
                int pos = any[(int)c];
                if (pos == 0) {
                    continue;
                }
                char d = s[i + pos - 1];
                go[c - 'a'] = d - 'a';
            }
            for (int i = 0; i < 26; i++) {
                if (go[i] != -1 && go[go[i]] != -1 && go[go[i]] != i) {
                    ok = false;
                }
            }
            if (ok) {
                ans.push_back(i);
            }
        }
        int l = i + 1, r = l + m - 1;
        if (r > n) {
            break;
        }
        hs = (hs + Q - (pw[m - 1] * a[i]) % Q) % Q;
        hs = (hs * P) % Q;
        hs = (hs + a[r]) % Q;
        int x = nxt[i];
        if (x != NONE) {
            if (x >= l && x <= r) {
                hs = (hs + Q - (pw[m - (x - l + 1)] * a[x]) % Q) % Q;
            }
            a[x] = NONE;
            hs = (hs + Q + (pw[m - (x - l + 1)] * a[x]) % Q) % Q;
        }
    }

    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}