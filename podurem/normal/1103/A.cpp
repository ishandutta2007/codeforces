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
    string s;
    cin >> s;
    int c = 0, c2 = 0;
    for (char x : s) {
        if (x == '1') {
            cout << 1 << " " << 1 + c++ * 2 << "\n";
        } else {
            cout << 2 << " " << 1 + c2++ << "\n";
        }
        c %= 2;
        c2 %= 4;
    }
}