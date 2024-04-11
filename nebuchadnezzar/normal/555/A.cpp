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
const int MAXN = 1e5 + 5;

int n, k;
vector <int> inp[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;

    int ans = n - 1;

    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int num;
            cin >> num;
            inp[i].puba(num);
        }
        ans += m - 1;
    }


    for (int i = 0; i < k; ++i) {
        if (inp[i][0] == 1) {
            for (int j = 1; j < szof(inp[i]) && j + 1 == inp[i][j]; ++j) {
                ans -= 2;
            }
        }
    }

    cout << ans << endl;

    return 0;
}