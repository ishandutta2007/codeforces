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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<pii, int> > mem;
    int last_id = 0;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op[0] == 'd') {
            set<pair<pii, int> > mem2;
            int prv = 0;
            while (sz(mem)) {
                auto cur = *mem.begin();
                mem.erase(mem.begin());
                int diff = cur.L.L - prv;
                cur.L.L -= diff;
                cur.L.R -= diff;
                mem2.insert(cur);
                prv = cur.L.R;
            }
            mem.swap(mem2);
        }
        else if (op == "erase") {
            int id;
            cin >> id;
            bool found = false;
            for (auto memb: mem)
                if (memb.R == id) {
                    mem.erase(memb);
                    found = true;
                    break;
                }
            if (!found)
                cout << "ILLEGAL_ERASE_ARGUMENT" << '\n';
        }
        else {
            int len;
            cin >> len;
            auto it = mem.begin();
            bool found = false;
            int prv = 0;
            while (!found and it != mem.end()) {
                if (prv + len <= it->L.L) {
                    last_id++;
                    mem.insert(MP(MP(prv, prv + len), last_id));
                    cout << last_id << '\n';
                    found = true;
                }
                else
                    prv = it->L.R;
                it++;
            }
            if (!found and prv + len <= m) {
                last_id++;
                mem.insert(MP(MP(prv, prv + len), last_id));
                cout << last_id << '\n';
                found = true;
            }
            if (!found)
                cout << "NULL\n";
        }
    }
    return 0;
}