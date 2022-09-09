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

int n, m;
int field[30][30];

int check(vector<int> arr) {
    for (int i = 0; i < n; ++i) {
        int num = 0;
        for (int j = 0; j < m; ++j) {
            if (arr[j] != field[i][j]) {
                ++num;
            }
        }
        if (num > 2) {
            return 0;
        }
    }
    return 1;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &field[i][j]);
            --field[i][j];
        }
    }

    vector<int> arr;
    for (int i = 0; i < m; ++i) {
        arr.puba(i);
    }

    if (check(arr)) {
        cout << "YES\n";
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            swap(arr[i], arr[j]);

            /*
            for (int num: arr) {
                cerr << num << " ";
            }   
            cerr << endl;
            */
            if (check(arr)) {
                cout << "YES\n";
                return 0;
            }

            swap(arr[i], arr[j]);
        }   
    }

    cout << "NO\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}