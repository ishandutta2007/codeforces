#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int max_n = 1e6 + 5;

int n;
vector<pii> gr[max_n];
vector<int> g[max_n];
vector<int> order;
bool used[max_n];
int col[max_n];
int v_col = 0;
int dp[max_n];

int sum[(int) 1e5];

void top_sort(int v) {
    if (used[v]) 
        return;
    used[v] = true;
    for(int i : g[v]) {
        top_sort(i);
    }
    order.emplace_back(v);
}

int infinite(int num) {
    int l = -1;
    int r = 1e5;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if (mid * (mid + 1) / 2 <= num) 
            l = mid;
        else 
            r = mid;
    }

    return (l + 1) * num - sum[l];
}

int comp_mush = 0;

void dfs(int v) {
    if (col[v] != 0)
        return;

    col[v] = v_col;

    for(auto i : gr[v]) {
        if (col[i.first] != 0 && col[i.first] != v_col) 
            dp[v_col] = max(dp[v_col], i.second + dp[col[i.first]]);
        else {
            comp_mush += infinite(i.second);
            //cout << i.second << " " << v << " " << comp_mush << endl;
            dfs(i.first);
        }
    }
}

void solve() {
    for(int i = 1;i < 1e5;i++) 
        sum[i] = sum[i - 1] + i * (i + 1) / 2;

    int m;
    cin >> n >> m;

    for(int i = 0;i < m;i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--; v2--;
        gr[v1].emplace_back(v2, w);
        g[v2].emplace_back(v1);
    }

    for(int i = 0;i < n;i++)
        top_sort(i);

    /*cout << "top_sort: ";
    for(int i : order) 
        cout << i + 1 << " ";
    cout << endl;*/

    for(int temp = n - 1;temp >= 0;temp--) {
        int st = order[temp];
        if (col[st] != 0)
            continue;

        v_col++;
        dfs(st);
        //cout << "dfs " << st << endl;
        dp[v_col] += comp_mush;
        comp_mush = 0;
    }

    int s;
    cin >> s;
    cout << dp[col[s - 1]] << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}