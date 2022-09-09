#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int MAXN = 1e5 + 5;

int n;
vector<pii> inp;
int d[MAXN];

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);

        inp.puba({a, b});
    }

    sort(bend(inp));

    int ans = n - 1;

    for (int i = 1; i < n; ++i) {
        int tmp = lower_bound(bend(inp), mapa(inp[i].ff - inp[i].ss, 0)) - inp.begin() - 1;
        if (tmp == -1) {
            d[i] = i;
        } else {
            d[i] = d[tmp] + i - tmp - 1;
        }
        ans = min(ans, d[i] + n - i - 1);
        //cerr << i << " " << d[i] << endl;
    }


    cout << ans << "\n";

    

    return 0;
}