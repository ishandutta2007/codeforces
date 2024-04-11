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

int n;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%d", &n);

    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        a.puba(num);
    }
    
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        b.puba(num);
    }

    vector<int> inds;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            inds.puba(i);
        }
    }

    if (szof(inds) == 1) {
        vector<int> have(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                have[a[i] - 1] = 1;
            }
        }
        a[inds[0]] = find(bend(have), 0) - have.begin() + 1;
    } else {
       vector<int> have(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                have[a[i] - 1] = 1;
            }
        }
        vector<int> res = a;
        vector<int> empty;
        for (int i = 0; i < n; ++i) {
            if (!have[i]) {
                empty.puba(i);
            }
        }
        for (int q = 0; q < 2; ++q) {
            for (int i = 0; i < 2; ++i) {
                res[inds[i]] = empty[i] + 1;
            }
            int vala = 0, valb = 0;
            for (int i = 0; i < n; ++i) {
                vala += (res[i] != a[i]);
                valb += (res[i] != b[i]);
            }
            if (vala == 1 && valb == 1) {
                break;
            }
            swap(empty[0], empty[1]);
        }
        a = res;
    }

    for (int num : a) {
        cout << num << " ";
    }           
    cout << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}