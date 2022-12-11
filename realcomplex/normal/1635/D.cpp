#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;
const int T = (int)1e7 + 10;
const int N = (int)2e5 + 10;
int nex[T][2];
int dep[T];
int idx;
bool mark[T];
bool vis[T];

void dfs(int x){
    if(vis[x]) return;
    vis[x]=true;
    int go;
    if(nex[x][0] != -1 && nex[nex[x][0]][0] != -1){
        go = nex[nex[x][0]][0];
        mark[go]=false;
        dfs(go);
    }
    if(nex[x][1] != -1){
        go = nex[x][1];
        mark[go]=false;
        dfs(go);
    }
}

int dp[N];
int S[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    for(int i = 0 ; i < T; i ++ ){
        nex[i][0] = nex[i][1] = -1;
    }
    int n, p;
    cin >> n >> p;
    int a;
    int mx;
    int root = 0;
    vector<int> lis;
    dp[0]=1;
    dp[1]=1;
    for(int i = 2; i < N; i ++ ){
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    S[0]=1;
    for(int i = 1; i < N; i ++ ){
        S[i]=(S[i-1]+dp[i])%MOD;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        mx = 0;
        for(int j = 30; j >= 0; j -- ){
            if((a & (1 << j))){
               mx = j;
               break;
            }
        }
        root = 0;
        for(int j = mx; j >= 0 ; j -- ){
            if((a & (1 << j))){
                if(nex[root][1] == -1){
                    idx ++ ;
                    dep[idx] = dep[root] + 1;
                    nex[root][1] = idx;

                }
                root = nex[root][1];
            }
            else{
                if(nex[root][0] == -1){
                    idx ++ ;
                    dep[idx] = dep[root] + 1;
                    nex[root][0] = idx;
                }
                root = nex[root][0];
            }
        }
        mark[root] = true;
        lis.push_back(root);
    }
    sort(lis.begin(), lis.end());
    for(auto x : lis){
        if(mark[x]){
            dfs(x);
        }
    }
    int res = 0;
    for(auto x : lis){
        if(mark[x] && p >= dep[x]){
            res += S[p-dep[x]];
            res %= MOD;
        }
    }
    cout << res << "\n";
    return 0;
}