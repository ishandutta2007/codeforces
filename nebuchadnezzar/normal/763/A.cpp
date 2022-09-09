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
vector<int> graph[MAXN];
int color[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &color[i]);
    }


    int worst = 0;
    int tot = 0;
    int mem = 0;

    for (int i = 0; i < n; ++i) {
        int num = 0;
        for (int to : graph[i]) {
            if (color[i] != color[to]) {
                //bad.puba({i, to});
                ++num;
            }
        }
        if (worst < num) {
            worst = num;
            mem = i;
        }
        tot += num;
    }

    if (worst * 2 == tot) {
        cout << "YES\n" << mem + 1 << "\n";
    } else {
        cout << "NO\n";
    }



    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}