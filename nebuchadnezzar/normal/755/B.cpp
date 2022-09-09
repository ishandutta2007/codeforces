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

map<string, int> ind;

int get_ind(string s) {
    if (!ind.count(s)) {
        int tmp = szof(ind);
        ind[s] = tmp;
    }
    return ind[s];
}

int n, m;
char buf[1000];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    vector<int> arr1, arr2;

    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        arr1.puba(get_ind(buf));
    }

    for (int i = 0; i < m; ++i) {
        scanf("%s", buf);
        arr2.puba(get_ind(buf));
    }

    vector<pii> know(szof(ind));

    for (int i : arr1) {
        know[i].ff = true;
    }

    for (int i : arr2) {
        know[i].ss = true;
    }

    int tot[2][2];
    memset(tot, 0, sizeof tot);

    for (int i = 0; i < szof(ind); ++i) {
        //cerr << know[i].ff << " " << know[i].ss << endl;
        tot[know[i].ff][know[i].ss]++;
    }

    int c = 0;
    while (true) {
        if (c & 1) {
            if (tot[1][1]) {
                --tot[1][1];
            } else if (tot[0][1]) {
                --tot[0][1];
            } else {
                cout << "YES\n";
                return 0;
            }
        } else {
            if (tot[1][1]) {
                --tot[1][1];
            } else if (tot[1][0]) {
                --tot[1][0];
            } else {
                cout << "NO\n";
                return 0;
            }
        }
        ++c;
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}