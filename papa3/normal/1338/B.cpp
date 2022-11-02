#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

vector<int> drogi[1000100];
int n;

int ma, mi = 1;

bool czy[10];

// ret if leaf
bool dfs(int gdzie, int skad = -1, int dist = 0) {
    int ile = 0;
    for (int i : drogi[gdzie]) {
        if (i == skad) {
            continue;
        }
        ile += dfs(i, gdzie, dist + 1);
    }
    if (ile)
        ma -= ile - 1;
    
    if (drogi[gdzie].size() == 1) {
        czy[dist % 2] = true;
    }
    return drogi[gdzie].size() == 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    ma = n - 1;
    for (int a, b, i = 1; i < n; i++) {
        cin >> a >> b;
        drogi[a].push_back(b);
        drogi[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (drogi[i].size() > 1) {
            dfs(i);
            break;
        }
    }
    
    if (czy[0] && czy[1]) mi = 3;
    
    cout << mi << " " << ma;
    
    return 0;
}/*

*/