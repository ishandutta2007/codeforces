#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e3 + 5;
int n, m, k;
bool adjm[sz][sz];
int a[sz][3];
int dp[sz][sz];
vector<int> adj[sz];
int lst[sz];

int main() {
    fast;
    cin >> n >> m >> k;
    foru(i, 0, n) {
        adjm[i][i] = 1;
        lst[i] = i;
        foru(j, 0, 3)cin >> a[i][j];
    }
    foru(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adjm[--x][--y] = 1;
        lst[y] = max(lst[y], x);
    }
    foru(i, 0, n) {
        adj[lst[i]].pb(a[i][2]);
    }
    foru(i, 0, n) {
        sort(adj[i].rbegin(), adj[i].rend());
    }
    ford(i, n - 1, 0) {
        foru(rk, 0, sz) {
            if (rk < a[i][0])dp[i][rk] = -1;
            else {
                dp[i][rk] = dp[i + 1][rk + a[i][1]];
                int ttsm = 0, cnt = 0;
                for (int x : adj[i]) {
                    ttsm += x;
                    cnt++;
                    if (rk + a[i][1] - cnt < 0 || dp[i + 1][rk + a[i][1] - cnt] == -1)break;
                    dp[i][rk] = max(dp[i][rk], dp[i + 1][rk + a[i][1] - cnt] + ttsm);
                }
            }
        }
    }
    cout << dp[0][k] << '\n';
    return 0;
}