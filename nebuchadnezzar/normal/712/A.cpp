#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 1e5 + 5;

int n;
ll a[MAXN];
ll b[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        a[i] = num;
    }

    b[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        b[i] = a[i] + a[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}