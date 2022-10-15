//Thanks to robs77 for this template
/***********HEADER***************/
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
/***********MACROS***************/
#define inf 100000000000000000
#define int long long
#define ll long long
#define F first
#define S second
#define pb push_back
#define ld long double
#define max(A,B) ((A)>(B))?(A):(B)
/*********VARIABLE****************/
using namespace std;
typedef pair<ll,ll> ii;
struct sol{ll val;ll lis;};
/******************************/

const int maxn = 1e3 + 100, mod = 1e9 + 993;
int n, m, maxw;
int q[maxn][2], b[maxn], c[maxn];
bool vis[maxn];
vector<int> e[maxn];
int ans = 0;
/*********FUNCTIONS**************/
void upd(pair<int, int> x){
    for (int i = maxw - x.first; i >= 0; i--)
        q[i + x.first][1] = max(q[i + x.first][1], q[i][0] + x.second);
}
 
pair<int, int> dfs(int v){
    pair<int, int> ret = make_pair(c[v], b[v]);
    vis[v] = 1;
    upd(make_pair(c[v], b[v]));
    for (int i = 0; i < e[v].size(); i++)
        if (!vis[e[v][i]]){
            pair<int, int> x = dfs(e[v][i]);
            ret.first += x.first;
            ret.second += x.second;
        }
    return ret;
}
/***********MAIN**************/

int32_t main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> maxw;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        if (!vis[i]){
            upd(dfs(i));
            for (int j = 0; j < maxn; j++)
                q[j][0] = max(q[j][0], q[j][1]), q[j][1] = 0;
        }
    
    for (int i = 0; i < maxn; i++)
        ans = max(ans, q[i][0]);
    cout << ans;
}