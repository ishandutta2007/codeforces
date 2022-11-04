#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const int MOD = (ll) 1e9 + 7;

const int N = 76;
const int M = 20;

int n;
string s;
int dp[N][1 << M];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void run() {
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
        
        vector<pair<int, int>> go;
        int cur = 0;
        for (int j = i; j < n; j++) {
            cur *= 2;
            cur += s[j] - '0';
            if (cur > M) {
                break;
            }
            
            if (cur > 0) {
                go.push_back({cur - 1, j + 1});
            }
        }
        
        for (int mask = 0; mask < (1 << M); mask++) {
            if (!dp[i][mask]) {
                continue;
            }
            
            for (auto &it : go) {
                add(dp[it.second][mask | (1 << it.first)], dp[i][mask]);
            }
        }
    }
    
    int ans = 0;
    for (int mask = 1; mask < (1 << M); mask++) {
        bool ok = true;
        for (int i = 0; i < M - 1; i++) {
            if (!(mask & (1 << i)) && (mask & (1 << (i + 1)))) {
                ok = false;
            }
        }
        
        if (ok) {
            for (int i = 0; i <= n; i++) {
                if (!dp[i][mask]) {
                    continue;
                }
                
                add(ans, dp[i][mask]);
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}