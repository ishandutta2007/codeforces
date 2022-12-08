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
            assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
        } else if (strcmp(TASK, "")) {
            assert(freopen(TASK".in", "r", stdin)); assert(freopen(TASK".out", "w", stdout));
        }
    #endif
    int t = 1;
    if (multiTest) {
        cin >> t;
    }
    while (t--) solve();
    return 0;
}

const int dd = (int)2e3 + 7;

int p[dd], spec[dd], used[dd];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= 2 * n + 1; ++i) {
        spec[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        spec[a] = b, spec[b] = a;
    }

    int t;
    cin >> t;
    int last = 2 * n + 1;
    for (int i = 1; i <= 2 * n; ++i) {
        if (t % 2 == i % 2) {
            if (spec[last] != -1 && !used[spec[last]]) {
                cout << spec[last] << endl;
                used[spec[last]] = 1;
                last = spec[last];
            } else {
                int ind = -1;
                for (int i = 1; i <= 2 * n; ++i) {
                    if (spec[i] != -1 && !used[i]) {
                        if (ind == -1 || p[i] > p[ind]) {
                            ind = i;
                        }
                    }
                }
                if (ind == -1) {
                    for (int i = 1; i <= 2 * n; ++i) {
                        if (!used[i]) {
                            if (ind == -1 || p[i] > p[ind]) {
                                ind = i;
                            }
                        }
                    }
                }
                cout << ind << endl;
                last = ind;
                used[ind] = 1;
            }
        } else {
            int x;
            cin >> x;
            last = x;
            used[x] = 1;
        }
    }
}