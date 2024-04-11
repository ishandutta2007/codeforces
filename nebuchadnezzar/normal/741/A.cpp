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
const double PI = atan2(0, -1);



int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<int> inp, inv(n, -1);

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        inp.puba(num);
        inv[num] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (inv[i] == -1) {
            cout << "-1\n";
            return 0;
        }
    }

    /*
    for (int i = 1; i < 1000; ++i) {
        vector<int> here(n);
        for (int j = 0; j < n; ++j) {
            int now = j;
            for (int k = 0; k < i; ++k) {
                now = inp[now];
            }
            here[j] = now;
        }
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (here[here[j]] != j) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << "\n";
            return 0;
        }
    }*/


    set<int> have;
    vector<bool> used(n);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = true;
            int now = inp[i];
            int c = 1;
            while (now != i) {
                used[now] = true;
                ++c;
                now = inp[now];
            }
            if (c % 2 == 0) {
                c /= 2;
            }
            have.insert(c);
        }
    }
    

    ll res = *have.begin();
    for (ll num : have) {
        res = res * num / __gcd(res, num);
    }

    cout << res << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}