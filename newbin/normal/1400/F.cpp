#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
int cnt = 0;
int n;
int a[22];
int sum[22];
const int maxn = 5050;
int nxt[maxn][9], fail[maxn], ed[maxn];
int root = 0, tot = 0;
queue<int> q;
void get_fail(){
    fors(i,0,9){
        if(nxt[root][i]) q.push(nxt[root][i]);
    }
    while(q.size()){
        int u = q.front(); q.pop();
        if(ed[fail[u]]) ed[u] = 1;
        fors(i,0,9){
            if(nxt[u][i]){
                fail[nxt[u][i]] = nxt[fail[u]][i];
                q.push(nxt[u][i]);
            }else nxt[u][i] = nxt[fail[u]][i];
        }
    }return;
}
void dfs(int p, int cur){
    if(cur > n) return;
    if(cur == n){
        int cur = root;
        fors(i,1,p){
            if(!nxt[cur][a[i]-1]){
                nxt[cur][a[i]-1] = ++tot;
            }
            cur = nxt[cur][a[i]-1];
        }
        ed[cur] = 1;
        cnt += (p-1);
        return;
    }
    fors(i,1,min(10, n-cur+1)){
        a[p] = i;
        sum[p] = sum[p-1]+i;
        int flag = 0;
        fors(j,0,p){
            int t = sum[p] - sum[j];
            if(n%t == 0 && n > t) flag = 1;
            if(flag) break;
        }
        if(!flag) dfs(p+1, cur+i);
    }
    return;
}
char s[maxn];
int dp[1050][maxn];
const int inf = 0x3f3f3f3f;
int main()
{
    scanf("%s", s+1);
    scanf("%d", &n);
    dfs(1, 0);
    get_fail();
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    int len = strlen(s+1);
    fors(i,0,len){
        fors(j,0,tot+1){
            if(dp[i][j] == inf) continue;
            int x = s[i+1]-'1';
            int to = nxt[j][x];
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            if(ed[to] == 0){
                dp[i+1][to] = min(dp[i+1][to], dp[i][j]);
            }
        }
    }
    int ans = inf;
    fors(i,0,tot+1) ans = min(ans, dp[len][i]);
    cout<<ans<<endl;
}