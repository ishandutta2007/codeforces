#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 20;
const int INF = 1e9 + 7;

int n, l, r, x;
int inp[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> l >> r >> x;

    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
    }

    int bdv = 1 << n;
    int ans = 0;    

    for (int i = 0; i < bdv; ++i) {
        int sum = 0;
        int mind = INF;
        int maxd = -INF;
        int tmp = i;
        for (int j = 0; j < n; ++j) {
            if (tmp & 1) {
                sum += inp[j];
                mind = min(mind, inp[j]);
                maxd = max(maxd, inp[j]);
            }
            tmp >>= 1;
        }
        if (l <= sum && sum <= r && maxd - mind >= x) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}