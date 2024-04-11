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

    int n;

    scanf("%d", &n);

    cout << "YES\n";

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int x = (x1 + x2 - 1) / 2;
        int y = (y1 + y2 - 1) / 2;
        cout << ((((x2 - x1) / 2) & 1) ^ (x & 1)) * 2 + ((((y2 - y1) / 2) & 1) ^ (y & 1)) + 1 << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}