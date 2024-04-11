#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)2e5 + 9;
vector<int> T[N];
bool vis[N];
int col[N];
int cnt1 = 0;

void dfs(int u, int bt){
    col[u] = bt;
    cnt1 += bt;
    vis[u] = true;
    for(auto x : T[u]){
        if(!vis[x]){
            dfs(x, !bt);
        }
    }
}

int main(){
    fastIO;
    int test;
    cin >> test;
    for(int p = 0 ; p < test; p ++ ){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i ++ ){
            T[i].clear();
            vis[i] = false;
            col[i] = -1;
        }
        int u, v;
        for(int i = 0 ;i  < m ; i ++ ){
            cin >> u >> v;
            T[u].push_back(v);
            T[v].push_back(u);
        }
        cnt1 = 0;
        dfs(1,1);
        if(cnt1 < n - cnt1){
            cout << cnt1 << "\n";
            for(int i = 1; i <= n; i ++ )
                if(col[i] == 1)
                    cout << i << " ";
        }
        else{
            cout << n - cnt1 << "\n";
            for(int i = 1; i <= n; i ++ )
                if(col[i] == 0)
                    cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}