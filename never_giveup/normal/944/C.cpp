#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(1339);

const ll llinf = 2e18 + 100;

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 300, LG = 17;

int n;

vector<int> e[maxn];

vector<int> q[maxn];

void dfs(int v){
    for (auto i : e[v]){
        dfs(i);
        if (q[i].size() > q[v].size())
            swap(q[i], q[v]);
        for (int j = 0; j < q[i].size(); j++)
            q[v][q[v].size() - 1 - j] ^= q[i][q[i].size() - 1 - j];
    }
    q[v].push_back(1);
}

int main()
{
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int par;
        cin >> par;
        e[par - 1].push_back(i);
    }
    dfs(0);
    int ans = 0;
    for (auto i : q[0])
        ans += i;
    cout << ans;
}