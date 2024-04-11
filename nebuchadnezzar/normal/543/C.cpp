#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 25;
const int INF = 1e9 + 7;
const int MAXK = 20;

int n, m;
string inp[MAXN];
int cost[MAXN][MAXN];
int mask[MAXN][26];
int rcost[MAXN][26];
int ansfor[1 << MAXK];

int rec(int now) {
    //cerr << now << endl;
    if (!now) {
        return 0;
    }
    if (ansfor[now] != -1) {
        return ansfor[now];
    }
    int ret = INF;
    int pos = 0;
    int tmp = now;
    while (!(tmp & 1)) {
        tmp >>= 1;
        ++pos;
    }
    for (int i = 0; i < m; ++i) {
        ret = min(ret, rec(now ^ (1 << pos)) + cost[pos][i]);
        ret = min(ret, rec(now & (~mask[i][inp[pos][i] - 'a'])) + rcost[i][inp[pos][i] - 'a']);
    }
    return ansfor[now] = ret;
}

int main() {    
    memset(ansfor, -1, sizeof ansfor);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 26; ++j) {
            int sum = 0;
            int maxn = 0;
            for (int k = 0; k < n; ++k) {
                if (inp[k][i] - 'a' == j) {
                    mask[i][j] |= 1 << k;
                    sum += cost[k][i];
                    maxn = max(maxn, cost[k][i]);
                }
            }
            rcost[i][j] = sum - maxn;
        }
    }

    

    cout << rec((1 << n) - 1) << endl;

    return 0;
}