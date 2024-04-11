#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

int dist[500][5001];
bool was[500][5001];

int s, d;
vector<int> stk;
void dfs(int x, int sum) {
    was[x][sum] = true;
    if (x == 0 && sum == s) {
        for(auto &w : stk) {
            cout << w;
        }
        exit(0);
    }
    range(num, 10) {
        int x2 = (x * 10 + num) % d;
        int sum2 = sum + num;
        if (sum2 > s) break;
        if (was[x2][sum2] || dist[x2][sum2] != dist[x][sum] + 1) continue;
        stk.push_back(num);
        dfs(x2, sum2);
        stk.pop_back();
    }
}

void solve() {
    cin >> d >> s;
    range(i, 500) range(j, 5001) dist[i][j] = -1;
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        auto [x, sum] = q.front();
        q.pop();
        range(num, 10) {
            int x2 = (x * 10 + num) % d;
            int sum2 = sum + num;
            if (sum2 > s) break;
            if (dist[x2][sum2] == -1) {
                q.push({x2, sum2});
                dist[x2][sum2] = dist[x][sum] + 1;
            }
        }
    }
    if (dist[0][s] == -1) {
        cout << "-1\n";
        return;
    }
    dfs(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}