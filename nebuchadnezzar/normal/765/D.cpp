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

    vector<int> inp;
    vector<int> good(n);
    vector<int> order;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        inp.puba(num);
        if (num == i) {
            good[i] = 1;
            ++m;
            order.puba(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!good[i]) {
            if (!good[inp[i]]) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << m << "\n";

    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            cout << c + 1 << " ";
            ++c;
        } else {
            cout << lower_bound(bend(order), inp[i]) - order.begin() + 1 << " ";
        }
    }

    cout << "\n";

    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            cout << i + 1 << " ";
        }
    }

    cout << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}