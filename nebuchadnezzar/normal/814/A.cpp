#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);

int n, k;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%d%d", &n, &k);
    
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        a.puba(num);
    }

    for (int i = 0; i < k; ++i) {
        int num;
        scanf("%d", &num);
        b.puba(num);
    }
    
    sort(bend(b));
    
    for (int& num : a) {
        if (num == 0) {
            num = b.back();
            b.pop_back();
        }
    }
    
    if (is_sorted(bend(a))) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}