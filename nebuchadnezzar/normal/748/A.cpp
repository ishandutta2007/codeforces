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

int n, m, k;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    --k;

    cout << k / (m * 2) + 1 << " " << k % (m * 2) / 2 + 1 << " " << "LR"[k & 1] << "\n";


    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}