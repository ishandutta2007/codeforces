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

ll findAns(const string &s) {
    ll ans = 0;
    for (int i = 0; i + 4 <= sz(s); i++) {
        string z = "haha";
        bool ok = true;
        for (int j = 0; j < 4; j++) {
            if (z[j] != s[i + j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    return ans;
}

pair<string, string> getBegEnd(string s) {
    string beg = "", ending = "";
    beg = s;
    if (sz(beg) > 3) {
        beg.resize(3);
    }
    reverse(s.begin(), s.end());
    ending = s;
    if (sz(ending) > 3) {
        ending.resize(3);
    }
    reverse(ending.begin(), ending.end());
    return {beg, ending};
}

struct Var {
    ll ans;
    string beg;
    string ending;

    Var() {
        ans = 0;
        beg = "";
        ending = "";
    }
    Var(string s) {
        ans = findAns(s);
        auto pr = getBegEnd(s);
        beg = pr.first;
        ending = pr.second;
    }
};

Var combine(Var a, Var b) {
    Var c;
    c.beg = getBegEnd(a.beg + b.beg).first;
    c.ending = getBegEnd(a.ending + b.ending).second;
    c.ans = a.ans + b.ans + findAns(a.ending + b.beg);
    return c;
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    map<string, Var> q;
    ll ans = 0;
    for (int _ = 0; _ < n; _++) {
        string varname;
        string op;
        cin >> varname >> op;
        if (op == ":=") {
            string s;
            cin >> s;
            q[varname] = Var(s);
        } else {
            string l, op2, r;
            cin >> l >> op2 >> r;
            Var newval = combine(q[l], q[r]);
            q[varname] = newval;
        }
        ans = q[varname].ans;
    }
    cout << ans << '\n';
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