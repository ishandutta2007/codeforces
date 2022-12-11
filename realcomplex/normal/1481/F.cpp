#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
vector<int> T[N];
vector<int> lis[N];
int sub[N];
int mx;

void dfs(int u, int dis){
    lis[dis].push_back(u);
    mx = max(mx, dis);
    sub[u]=1;
    for(auto x : T[u]){
        dfs(x, dis + 1);
        sub[u] += sub[x];
    }
}

bool comp(int x, int y){
    return sub[x] < sub[y];
}

vector<int> ids[N];
vector<int> vals;

const int M = 450;
int dp[M][N];
char bit[N];

int main(){
    fastIO;
    int n, x;
    cin >> n >> x;
    int par;
    for(int i = 2; i <= n; i ++ ){
        cin >> par;
        T[par].push_back(i);
    }
    dfs(1,0);
    for(int i = 0 ; i <= mx ; i ++ ){
        ids[(int)lis[i].size()].push_back(i);
    }
    for(int i = 0 ; i <= n; i ++ ){
        if(ids[i].size() > 0)
            vals.push_back(i);
    }
    int m = vals.size();
    for(int i = 0 ;i <= m ; i ++ ){
        for(int j = 0 ; j <= x; j ++ ){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j <= x; j ++ ){
            if(dp[i][j] == -1) continue;
            for(int d = 0 ; j + d * vals[i] <= x && d <= (int)ids[vals[i]].size(); d ++ ){
                dp[i+1][j + d * vals[i]] = d;
            }
        }
    }
    if(dp[m][x] != -1){
        cout << mx + 1 << "\n";
        for(int i = 1; i <= n; i ++ ){
            bit[i]='b';
        }
        int cur = x;
        for(int i = m ; i > 0 ;i -- ){
            for(int j = 0 ; j < dp[i][cur]; j ++ ){
                for(auto f : lis[ids[vals[i-1]][j]]){
                    bit[f] = 'a';
                }
            }
            cur -= dp[i][cur] * vals[i-1];
        }
        for(int i = 1; i <= n; i ++ ){
            cout << bit[i];
        }
        cout << "\n";
        return 0;
    }
    cout << mx + 2 << "\n";
    for(int i = 1; i <= n; i ++ ){
        bit[i]='b';
    }
    pair<int,char> fa = mp(x, 'a'), fb = mp(n - x, 'b');
    for(int i = 0 ; i <= mx; i ++ ){
        if(fa < fb) swap(fa, fb);
        sort(lis[i].begin(), lis[i].end(), comp);
        while(!lis[i].empty() && fa.fi > 0){
            bit[lis[i].back()] = fa.se;
            lis[i].pop_back();
            fa.fi -- ;
        }
        while(!lis[i].empty() && fb.fi > 0){
            bit[lis[i].back()] = fb.se;
            lis[i].pop_back();
            fb.fi -- ;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cout << bit[i];
    }
    return 0;
}