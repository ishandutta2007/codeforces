#include <bits/stdc++.h>
    #ifdef PoDuReM
        #define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #else
        #define err(...) 42
    #endif

typedef long long ll;

using namespace std;

#define TASK ""
#define multiTest 0

void solve();
int main() {
    #ifndef PoDuReM
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (!strcmp(TASK, "input")) {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (strcmp(TASK, "")) {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    int t = 1;
    if (multiTest) {
        cin >> t;
    }
    while (t--) solve();
    return 0;
}

void solve() {
    while (true) {
        string s;
        cin >> s;
        if (s == "end") {
            return;
        }
        int x = 0, y = 1;
        while (true) {
            cout << "? " << x << " " << y << endl;
            string t;
            cin >> t;
            if (t == "x") {
                break;
            }
            x = (x == 0 ? 1 : x * 2);
            y = x * 2;
        }
        int X = x;
        y = min(y, (int)1e9);
        while (y - x > 1) {
            int m = (x + y) / 2;
            cout << "? " << X << " " << m << endl;
            string t;
            cin >> t;
            if (t == "x") {
                y = m;
            } else {
                x = m;
            }
        }
        cout << "! " << y << endl;
    }
}