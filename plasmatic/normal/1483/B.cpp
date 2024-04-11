// ./b-playlist.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const int MN = 1e5 + 1;
int N;
    // A[MN];

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

void solve() {
    cin >> N;
    set<int> can;
    set<pii> val;
    for (auto i = 0; i < N; i++) {
        int x; cin >> x;
        val.emplace(i, x);
    }
    auto nxt = [&] (int k) {
        auto ptr = val.upper_bound({k, INF});
        if (ptr == val.end()) return val.begin()->second;
        return ptr->second;
    };
    auto nxtPtr = [&] (int k) {
        auto ptr = val.upper_bound({k, INF});
        if (ptr == val.end()) return val.begin();
        return ptr;
    };
    auto get = [&] (int idx) { return val.lower_bound({idx, -1}); };
    for (auto [i, x] : val) {
        if (gcd(x, nxt(i)) == 1)
            can.insert(i);
    }

    int cur = -1;
    vector<int> del;
    while (!can.empty()) {
        auto _go = can.upper_bound(cur);
        if (_go == can.end()) // cycle to start
            _go = can.begin();
        int go = *_go;

        // for (auto x : can)
        //     printf("can=%d\n", x);
        // fflush(stdout);
        auto canNxtP = nxtPtr(go), canCurP = get(go);
        // printf("cur=%d go=%d nxt=(%d,%d) cur=(%d,%d)\n", cur,go,canNxtP->first,canNxtP->second,canCurP->first,canCurP->second);  fflush(stdout);
        can.erase(go);

        // add idx
        cur = canCurP->first;
        del.push_back(canNxtP->first);
        // assert(0);
        if (can.count(canNxtP->first)) {
            can.erase(canNxtP->first);
        }
        val.erase(canNxtP);
        if (val.empty()) break;

        // check if new
        if (gcd(canCurP->second, nxt(go)) == 1)
            can.insert(canCurP->first);
    }

    cout << del.size() << ' ';
    for (auto x : del) cout << x+1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        // printf("===TC\n");
        solve();

        // Reset
    }
}