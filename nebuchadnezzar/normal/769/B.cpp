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
const int MAXN = 105;

int arr[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    vector<int> order;
    for (int i = 0; i < n; ++i) {
        order.puba(i);
    }

    sort(order.begin() + 1, order.end(), [&](int a, int b) {return arr[a] > arr[b];});

    vector<int> available;
    available.puba(0);

    vector<pii> pairs;
    for (int i = 1; i < n; ++i) {
        while (szof(available) && arr[available.back()] == 0) {
            available.pop_back();
        }
        if (!szof(available)) {
            cout << "-1\n";
            return 0;
        }
        pairs.puba({available.back(), order[i]});
        --arr[available.back()];
        available.puba(order[i]);
    }

    cout << szof(pairs) << "\n";

    for (pii p : pairs) {
        cout << p.ff + 1 << " " << p.ss + 1 << "\n";
    }


    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}