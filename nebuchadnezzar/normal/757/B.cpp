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
const int MAXN = 1e5 + 5;

int n;
int res[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        for (int j = 2; j * j <= num; ++j) {
            if (num % j == 0) {
                res[j]++;
                while (num % j == 0) {
                    num /= j;
                }
            }
        }
        if (num != 1) {
            res[num]++;
        }
    }

    int ans = 1;
    for (int i = 0; i < MAXN; ++i) {
        ans = max(ans, res[i]);
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}