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
const int MAXN = 1e6 + 100;

int n;
int arr[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    for (int i = 2; i < MAXN; ++i) {
        if (!arr[i]) {
            for (int j = i * 2; j < MAXN; j += i) {
                arr[j] = true;
            }
        }
    }

    scanf("%d", &n);

    for (int i = 1; i <= 1000; ++i) {
        if (arr[n * i + 1]) {
            cout << i << "\n";
            return 0;
        }
    }


    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}