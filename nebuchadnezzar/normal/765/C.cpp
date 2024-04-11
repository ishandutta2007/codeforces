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

    int k, a, b;
    scanf("%d%d%d", &k, &a, &b);

    if (a < k && b < k) {
        cout << "-1\n";
        return 0;
    }

    if ((a < k && b % k != 0) || (b < k && a % k != 0)) {
        cout << "-1\n";
        return 0;
    }

    int ans = a / k + b / k;
    
    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}