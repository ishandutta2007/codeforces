#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int MAXN = 1e5 + 5;
const int bd = 18;

int bdarr[bd];
int n, q;
int inp[MAXN], arr[MAXN];
pii sparse[bd][MAXN];
int biggest[MAXN];

pii get_max(int l, int r) {
    int t = biggest[r - l + 1];
    return max(sparse[t][r], sparse[t][l + bdarr[t] - 1]);
}

ll calc(int l, int r) {
    //cerr << l << " " << r << endl;
    if (r < l) {
        return 0;
    }
    auto p = get_max(l, r);
    //cerr << "from " << l << " " << r << " to " << l << " " << p.ss - 1 << " and " << p.ss + 1 << " " << r << endl;
    return calc(l, p.ss - 1) + calc(p.ss + 1, r) + (ll) p.ff * (p.ss - l + 1) * (r - p.ss + 1);
}

int main() {
    bdarr[0] = 1;
    for (int i = 1; i < bd; ++i) {
        bdarr[i] = bdarr[i - 1] * 2;
    }
    for (int i = 1; i < MAXN; ++i) {
        biggest[i] = biggest[i - 1];
        if (bdarr[biggest[i] + 1] <= i) {
            ++biggest[i];
        }
    }
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; ++i) {
        scanf("%d", inp + i);
    }

    for (int i = 0; i < n - 1; ++i) {
        arr[i] = abs(inp[i] - inp[i + 1]);        
        sparse[0][i] = {arr[i], i};
    }    

    for (int i = 1; i < bd; ++i) {
        for (int j = bdarr[i] - 1; j < n; ++j) {
            sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j - bdarr[i - 1]]);
        }
    }

    //cerr << get_max(1, 1).ss << endl;

    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        cout << calc(l, r - 1) << "\n";
    }


    return 0;
}