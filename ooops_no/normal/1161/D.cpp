#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 998244353;
const int N = 2010;
vector<pair<int,int>> g[N];
vector<int> color(N);
string s;
bool flag = 0, bad = 0;
int sum = 0, need1, need2;

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

void add_edge(int a, int b, int c){
    g[a].pb({b, c});
    g[b].pb({a, c});
}

void dfs(int v){
    if (v == need1 || v == need2) bad = 1;
    for (auto to : g[v]){
        if (color[to.first] == 0){
            if (to.second == 1) color[to.first] = (color[v] == 1 ? 2 : 1);
            else color[to.first] = color[v];
            dfs(to.first);
        }
        else if (color[to.first] == color[v] && to.second == 1){
            flag = 1;
        }
        else if (color[to.first] != color[v] && to.second == 0){
            flag = 1;
        }
    }
}

void solve(int i){
    for (int i = 0; i < N; i++) g[i].clear();
    fill(color.begin(), color.end(), 0);
    int n = s.size();
    add_edge(n + i, n + i + 1, 1);
    need1 = n + i, need2 = n + i + 1;
    add_edge(n, n + i + 1, 0);
    for (int j = 0; j < i; j++){
        add_edge(n + j, n + i - j - 1, 0);
    }
    int now = n;
    for (int j = 0; j < n; j++){
        add_edge(j, n - j - 1, 0);
        if (j + i < n){
            if (s[j] == '0'){
                add_edge(j, n + i, 0);
            }
            else if (s[j] == '1'){
                add_edge(j, n + i + 1, 0);
            }
        }
        else{
            if (s[j] == '1'){
                add_edge(j, now, 1);
            }
            else if (s[j] == '0'){
                add_edge(j, now, 0);
            }
            now++;
        }
    }
    int ans = 1;
    flag = 0;
    for (int j = 0; j < n + i + 2; j++){
        if (color[j] == 0){
            bad = 0;
            color[j] = 1;
            dfs(j);
            if (!bad){
                ans = mul(ans, 2);
            }
        }
    }
    if (!flag) sum = add(sum, ans);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (int i = 1; i < s.size(); i++){
        solve(i);
    }
    cout << sum << endl;
    return 0;
}