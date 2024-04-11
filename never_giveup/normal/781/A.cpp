#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 2e9 + 100;

int n;

vector<int> e[maxn];

int ans[maxn], answer;

void dfs(int v, int par){
    answer = max(answer, ans[v]);
    int v1 = ans[v], v2 = (par == -1 ? -1 : ans[par]);
    int x = 0;
    for (int i = 0; i < e[v].size(); i++)
        if (e[v][i] != par){
            while (v1 == x || v2 == x)
                x++;
            ans[e[v][i]] = x;
            x++;
            dfs(e[v][i], v);
        }
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs(0, -1);
    cout << answer + 1 << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
}