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
const int MAXS = 1 << 11;

int n;
LL inp[MAXS];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;
    int tmp = (1 << (n + 1)) - 2;

    for (int i = 0; i < tmp; ++i) {
        cin >> inp[i + 2];
    }

    LL ans = 0;
    for (int i = (tmp + 2) / 2 - 1; i >= 1; --i) {
        ans += max(inp[i * 2], inp[i * 2 + 1]) - min(inp[i * 2], inp[i * 2 + 1]);
        inp[i] += max(inp[i * 2], inp[i * 2 + 1]);
    }

    cout << ans << endl;

    return 0;            
}