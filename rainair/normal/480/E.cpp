/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-17 18:31:21
 */
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

const int MAXN = 2000+5;
char str[MAXN][MAXN];
int n,m,k;
P q[MAXN];
int ans[MAXN];
int f[MAXN][MAXN];
int up[MAXN][MAXN],down[MAXN][MAXN];

inline int get(){
    FOR(i,1,n){
        FOR(j,1,m){
            if(str[i][j] == 'X'){
                f[i][j] = 0;continue;
            }
            f[i][j] = std::min(f[i-1][j-1],std::min(f[i-1][j],f[i][j-1]))+1;
            up[i][j] = up[i-1][j]+1;
        }
    }
    ROF(i,n,1){
        ROF(j,m,1){
            if(str[i][j] == 'X') continue;
            down[i][j] = down[i+1][j]+1;
        }
    }
    int ans = 0;
    FOR(i,1,n) FOR(j,1,m) ans = std::max(ans,f[i][j]);
    return ans;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%s",str[i]+1);
    FOR(i,1,k){
        int x,y;scanf("%d%d",&x,&y);
        str[x][y] = 'X';q[i] = MP(x,y);
    }
    ans[k] = get();
//    FOR(i,1,n) FOR(j,1,m) printf("%d%c",up[i][j]," \n"[j==m]);
/*    str[q[k].fi][q[k].se] = '?';
    FOR(x,1,n){
        if(str[x][q[k].se] != 'X') up[x][q[k].se] = up[x-1][q[k].se]+1;
        else up[x][q[k].se] = 0;
    }
    ROF(x,n,1){
        if(str[x][q[k].se] != 'X') down[x][q[k].se] = down[x+1][q[k].se]+1;
        else down[x][q[k].se] = 0;
    }*/
    ROF(i,k,2){
        str[q[i].fi][q[i].se] = '?';
//        FOR(i,1,n) printf("%s\n",str[i]+1);
//        puts("");
//        DEBUG(q[i].fi);DEBUG(q[i].se);
        FOR(x,1,n){
            if(str[x][q[i].se] != 'X') up[x][q[i].se] = up[x-1][q[i].se]+1;
            else up[x][q[i].se] = 0;
         }
//if(i==k)        FOR(i,1,n) FOR(j,1,m) printf("%d%c",up[i][j]," \n"[j==m]);
        ROF(x,n,1){
            if(str[x][q[i].se] != 'X') down[x][q[i].se] = down[x+1][q[i].se]+1;
            else down[x][q[i].se] = 0;
        }
        ans[i-1] = ans[i];bool flag = true;
//        puts("");
//if(i==k)        FOR(i,1,n) FOR(j,1,m) printf("%d%c",down[i][j]," \n"[j==m]);
        while(flag){
            flag = false;
            int t = ans[i-1]+1;
            if(t > std::min(n,m)) continue;
            if(t == 1){
                FOR(i,1,n) FOR(j,1,m){
                    if(str[i][j] != 'X'){
                        flag = true;
                        break;
                    }
                }
                if(flag) ans[i-1]++;
                continue;
            }
            std::deque<int> q1,q2;
            FOR(x,1,t-1){
                while(!q1.empty() && up[q[i].fi][q1.back()] >= up[q[i].fi][x]) q1.pop_back();q1.pb(x);
                while(!q2.empty() && down[q[i].fi][q2.back()] >= down[q[i].fi][x]) q2.pop_back();q2.pb(x);
            }
            FOR(r,t,m){
                int l = r-t+1;
                while(!q1.empty() && q1.front() < l) q1.pop_front();
                while(!q2.empty() && q2.front() < l) q2.pop_front();
                while(!q1.empty() && up[q[i].fi][q1.back()] >= up[q[i].fi][r]) q1.pop_back();q1.pb(r);
                while(!q2.empty() && down[q[i].fi][q2.back()] >= down[q[i].fi][r]) q2.pop_back();q2.pb(r);
                int t1 = up[q[i].fi][q1.front()],t2 = down[q[i].fi][q2.front()];
                //DEBUG(r),DEBUG(t1),DEBUG(t2);
                if(t1+t2-1 >= t){
                    flag = true;break;
                }
 //               while(!q1.empty() && up[q[i].fi][q1.back()] >= up[q[i].fi][r]) q1.pop_back();q1.pb(r);
//                while(!q2.empty() && down[q[i].fi][q2.back()] >= down[q[i].fi][r]) q2.pop_back();q2.pb(r);
            }
            if(flag) ans[i-1]++;
        }
    }
    FOR(i,1,k) printf("%d\n",ans[i]);
    return 0;
}