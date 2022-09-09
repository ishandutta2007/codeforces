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
const int MAXN = 1e6 + 5;

int k;

vector <pii > ans;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> k;

    if (k % 2 == 0) {
        cout << "NO\n";
        return 0;
    }

    int numv = 1 + (k - 1) * 2;

    for (int i = 1; i < k; ++i) {
        ans.puba(mapa(0, i));
        for (int j = 0; j < k - 1; ++j) {
            ans.puba(mapa(i, k + j));
        }
    }

    for (int i = 0; i < k - 1; i += 2) {
        ans.puba(mapa(k + i, k + i + 1));
    }

    int n = szof(ans);

    for (int i = 0; i < n; ++i) {
        ans.puba(mapa(ans[i].ff + numv, ans[i].ss + numv));
    }
    ans.puba(mapa(0, numv));

    n = numv * 2;

    cout << "YES\n";
    cout << n << " " << szof(ans) << endl;
    for (int i = 0; i < szof(ans); ++i) {
        cout << ans[i].ff + 1 << " " << ans[i].ss + 1 << endl;
    }


    return 0;
}