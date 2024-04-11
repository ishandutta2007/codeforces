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

int n;

vector <pair<pair<ll, ll>, int>> v;
vector <pii> inp;

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    int x1, x2;

    scanf("%d%d", &x1, &x2);

    for (int i = 0; i < n; ++i) {
        int k, b;
        scanf("%d%d", &k, &b);
        
        v.puba(mapa(mapa((ll) x1 * k + b, (ll) x2 * k + b), i));
        inp.puba(mapa(k, b));
    }

    sort(bend(v));

    for (int i = 0; i < n - 1; ++i) {
        if ((ll) inp[v[i].ss].ff * x2 + inp[v[i].ss].ss > (ll) inp[v[i + 1].ss].ff * x2 + inp[v[i + 1].ss].ss) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}