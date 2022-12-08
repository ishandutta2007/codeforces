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

void solve() {
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; ++i) {
        int r, x;
        cin >> r;
        set<int> T;
        for (int j = 0; j < r; ++j) {
            cin >> x;
            T.insert(x);
        }
        set<int> nS;
        if (S.size() == 0) S = T;
        else {
            for (int j : S) {
                if (T.find(j) != T.end()) {
                    nS.insert(j);
                }
            }
            S = nS;
        }
    }
    for (int i : S) {
        cout << i << " ";
    }
    cout << "\n";
}