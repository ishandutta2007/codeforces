#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000 + 5;
int n,m,q;
char str[MAXN];
int a[MAXN][MAXN],f[MAXN][MAXN];
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int main(){
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,n){
        scanf("%s",str+1);
        FOR(j,1,m) a[i][j] = str[j]-'0';
    }
    std::queue<P> qq;
    FOR(i,1,n){
        FOR(j,1,m){
            bool flag = 0;
            FOR(k,0,3){
                int ii = i+dx[k],jj = j+dy[k];
                if(ii >= 1 && ii <= n && jj >= 1 && jj <= m) flag |= (a[i][j] == a[ii][jj]);
            }
            if(flag) f[i][j] = 0,qq.push(MP(i,j));
            else f[i][j] = 1e9;
        }
    }
    while(!qq.empty()){
        P v = qq.front();qq.pop();
        FOR(i,0,3){
            int xx = v.fi+dx[i],yy = v.se+dy[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && f[xx][yy] > f[v.fi][v.se]+1){
                f[xx][yy] = f[v.fi][v.se]+1;
                qq.push(MP(xx,yy));
            }
        }
    }
    FOR(i,1,q){
        int x,y;LL p;scanf("%d%d%lld",&x,&y,&p);
        if(p <= f[x][y] || f[x][y] == 1e9) printf("%d\n",a[x][y]);
        else printf("%lld\n",a[x][y]^((p-f[x][y])&1));
    }
    return 0;
}