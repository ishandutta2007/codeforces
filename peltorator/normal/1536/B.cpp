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

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    string s;
    cin >> s;
    set<string> q;
    for (int i = 0; i < n; i++) {
        string cur = "";
        for (int j = i; j < i + 3; j++) {
            cur.push_back(s[j]);
            q.insert(cur);
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        string z;
        z.push_back(c);
        if (!q.count(z)) {
            cout << z << '\n';
            return 0;
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        string z;
        z.push_back(c);
        for (int d = 'a'; d <= 'z'; d++) {
            z.push_back(d);
            if (!q.count(z)) {
                cout << z << '\n';
                return 0;
            }
            z.pop_back();
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        string z;
        z.push_back(c);
        for (int d = 'a'; d <= 'z'; d++) {
            z.push_back(d);
            for (int e = 'a'; e <= 'z'; e++) {
                z.push_back(e);
                if (!q.count(z)) {
                    cout << z << '\n';
                    return 0;
                }
                z.pop_back();
            }
            z.pop_back();
        }
    }

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