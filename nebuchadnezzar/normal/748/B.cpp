#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    string a, b;
    cin >> a >> b;
    vector<set<int>> to(26);

    for (int i = 0; i < szof(a); ++i) {
        to[a[i] - 'a'].insert(b[i] - 'a');
        to[b[i] - 'a'].insert(a[i] - 'a');
    }

    vector<pii> ans;
    for (int i = 0; i < 26; ++i) {
        if (szof(to[i])) {
            //cerr << i << " " << szof(to[i]) << " " << *to[i].begin() << endl;
            if (szof(to[i]) > 1 || szof(to[*to[i].begin()]) != 1 || *to[*to[i].begin()].begin() != i) {
                cout << "-1\n";
                return 0;
            }
            if (*to[i].begin() > i) {
                ans.puba({i, *to[i].begin()});
            }
        }
    }

    cout << szof(ans) << "\n";

    for (auto p : ans) {
        cout << (char) (p.ff + 'a') << " " << (char) (p.ss + 'a') << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}