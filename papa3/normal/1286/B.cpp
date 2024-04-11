#include <bits/stdc++.h>

using namespace std;

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

bool used[1000010];
int c[1000010];
vector<int> drogi[1000010];
int res[1000010];
int dp[1000010];
bool wrong;

void dfs(int gdzie) {
    dp[gdzie] = 1;
    int ile = 0;
    for (int i = 1; ; i++) {
        if (!used[i]) {
            ile++;
            if (ile > c[gdzie]) {
                res[gdzie] = i;
                used[i] = true;
                break;
            }
        }
    }
    
    for (int i : drogi[gdzie]) {
        dfs(i);
        dp[gdzie] += dp[i];
    }
    
    if (c[gdzie] + 1 > dp[gdzie]) {
        wrong = true;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int a, i = 1; i <= n; i++) {
        cin >> a >> c[i];
        drogi[a].push_back(i);
    }
    
    dfs(drogi[0][0]);
    if (wrong) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << res[i] << " ";
        }
    }
    
    return 0;
}/*
5
0 1
1 4
2 1
3 0
2 0

*/