#include <bits/stdc++.h>
#define maxn 155
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define mod 1000000007
#define debug
using namespace std;

int dp[2][2][maxn][maxn][maxn];

int cur[2][2][maxn][maxn];
int sum[2][2][maxn][maxn];

int n,m;

void acc(){
    for(int a=0;a<2;a++)
        for(int b=0;b<2;b++){
            sum[a][b][0][0] = cur[a][b][0][0];
            for(int i=1;i<m;i++)
                sum[a][b][i][0] = (sum[a][b][i-1][0]+cur[a][b][i][0]) % mod;
            for(int j=1;j<m;j++){
                sum[a][b][0][j] = (sum[a][b][0][j-1]+cur[a][b][0][j]) % mod;
                for(int i=1;i<m;i++){
                    sum[a][b][i][j] = sum[a][b][i-1][j] + sum[a][b][i][j-1] - sum[a][b][i-1][j-1];
                    sum[a][b][i][j] = ((sum[a][b][i][j]%mod+cur[a][b][i][j])%mod+mod)%mod;
                }
            }
        }
}

int getsum(int a,int b,int x1,int x2,int y1,int y2){
    int r = sum[a][b][x2][y2];
    if(x1) r -= sum[a][b][x1-1][y2];
    r = (r%mod+mod)%mod;
    if(y1) r -= sum[a][b][x2][y1-1];
    r = (r%mod+mod)%mod;
    if(x1 && y1)
        r += sum[a][b][x1-1][y1-1];
    r = (r%mod+mod)%mod;
    return r;
}

int get(int up,int down,int pos,int y1,int y2){
    int &r = dp[up][down][pos][y1][y2];
    if(y1 > y2)
        return 0;
    if(r+1)
        return r;
    if(pos == n)
        return 0;
    r = 1;
    
    for(int fu=0;fu<2;fu++)
        for(int fd=0;fd<2;fd++){
            
            if(up == 0 && fu == 1) continue;
            if(down == 0 && fd == 1) continue;
            int l1, r1, l2, r2;
            
            l2 = y1;
            r2 = m-1;
            if(up == 0) r2 = y2;
            if(up == 1 && fu == 1)
                l2 = y2;
            if(up == 1 && fu == 0)
                r2 = y2-1;
                
            l1 = 0;
            r1 = y2;
            if(down == 0)
                l1 = y1;
            if(down == 1 && fd == 1)
                r1 = y1;
            if(down == 1 && fd == 0)
                l1 = y1+1;
            
            int s = getsum(fu,fd,l1,r1,l2,r2); 
            if(up == 1 && down == 1 && pos == 0 && y1 == 0 && y2 == 1)
                debug("+ get %d %d %d~%d %d~%d -> %d\n",fu,fd,l1,r1,l2,r2,s);
            r += s;
            r %= mod;
        }
    
    debug("dp[%d][%d][%d][%d][%d] = %d\n",up,down,pos,y1,y2,r);
    return r;
    for(int a=0;a<m;a++)
        for(int b=a;b<m;b++){
            if(b < y1 || a > y2) continue;
            if(a < y1 && !down) continue;
            if(b > y2 && !up) continue;
            int fu = up, fd = down;
            if(b < y2) fu = 0;
            if(a > y1) fd = 0;
            r += get(fu,fd,pos+1,a,b);
            r %= mod;
        }
    return r;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        acc();
        for(int f1=0;f1<2;f1++)
            for(int f2=0;f2<2;f2++)
                for(int a=0;a<m;a++)
                    for(int b=0;b<m;b++)
                        cur[f1][f2][a][b] = get(f1,f2,i,a,b);
    }
    for(int i=0;i<n;i++)
        for(int a=0;a<m;a++)
            for(int b=a;b<m;b++){
                ans = (ans + get(1,1,i,a,b));
                ans %= mod;
                debug("get(1,1,%d,%d,%d) = %d\n",i,a,b,get(1,1,i,a,b));
            }
    printf("%d\n",ans);
}