#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

int n;

ll a[maxn], s[2];

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll answer = 0;
    for (int i = 0; i < n - 1; i++){
        ll x = max(0ll, s[1] + abs(a[i] - a[i + 1]));
        ll y = max(0ll, s[0] + abs(a[i] - a[i + 1]) * -1);
        answer = max(answer, max(x, y));
        s[0] = x;
        s[1] = y;
    }
    cout << answer;
}

/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 100, inf = 1e9 + 100;

int in[maxn], fup[maxn], tnow;

bool vis[maxn];

int n;

ll m;

ll s[maxn];

ll br;

ll pt;

vector<int> e[maxn];

void dfs(int v, int par){
    in[v] = tnow;
    tnow++;
    vis[v] = 1;
    fup[v] = in[v];
    for (int i = 0; i < e[v].size(); i++)
    if (e[v][i] != par){
        if (vis[e[v][i]])
            fup[v] = min(fup[v], in[e[v][i]]);
        else{
            dfs(e[v][i], v), fup[v] = min(fup[v], fup[e[v][i]]);
            if (fup[e[v][i]] > in[v])
                s[e[v][i]]++, s[v]++, br++;
        }
    }
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gift.in");
    //ofstream cout("gift.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        if (v == u)
            pt++;
        else
        e[v].push_back(u),
        e[u].push_back(v);
    }
    dfs(0, -1);
    for (int i = 1; i < n; i++)
        if (!vis[i]){
            cout << 0;
            return 0;
        }
    m -= pt;
    ll answer = m * (m - 1) / 2 - br * (br - 1) / 2;
    for (int i = 0; i < n; i++)
        answer += s[i] * (s[i] - 1) / 2;
    cout << answer + pt * (pt - 1) / 2 + pt * m;
}
*/