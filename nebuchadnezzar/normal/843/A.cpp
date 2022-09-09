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



int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);
    vector<int> arr;
    vector<int> all;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        arr.puba(num);
    }

    all = arr;
    sort(bend(all));

    for (int& num : arr) {
        num = lower_bound(bend(all), num) - all.begin();
    }

    vector<vector<int>> ans;
    vector<bool> used(n);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int cur = arr[i];
            vector<int> now = {i};
            used[i] = true;
            while (cur != i) {
                now.puba(cur);
                used[cur] = true;
                cur = arr[cur];
            }
            sort(bend(now));
            ans.puba(now);
        }
    }

    cout << szof(ans) << "\n";

    for (auto& v : ans) {
        cout << szof(v) << " ";
        for (int num : v) {
            cout << num + 1 << " ";
        }
        cout << "\n";
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}