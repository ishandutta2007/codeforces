#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;

ll gcd(ll a, ll b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    string s;
    cin >> s;
    map<ll, int> lastPosition;
    vector<int> ans(n);
    int d = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            d++;
        } else {
            k++;
        }
        int curGCD = gcd(d, k);
        int curd = d / curGCD;
        int curk = k / curGCD;
        ll hash = curd * INF + curk;
        if (lastPosition.count(hash)) {
            ans[i] = ans[lastPosition[hash]] + 1;
        } else {
            ans[i] = 1;
        }
        lastPosition[hash] = i;
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}