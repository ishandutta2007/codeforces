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
#include <assert.h>
#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;
const int dx[4] = {-1,-1,1,1};
const int dy[4] = {1,-1,-1,1};
//    
bool vis[5][MAXN],used[5][MAXN][5]; // up,left,down,right

int n,m,sx,sy;
int zt,cnt,ans;
char str[1231];

inline int getk(int x,int y,int zt){
    int res = INT_MAX;
    if(zt == 0) res = std::min(x-1,m-y);
    if(zt == 1) res = std::min(x-1,y-1);
    if(zt == 2) res = std::min(n-x,y-1);
    if(zt == 3) res = std::min(n-x,m-y);
    return res;
}

inline bool pd(int x,int y){
    return (x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m);
}

inline bool pdans(int x){
 //   FOR(i,0,1) FOR(j,0,1) FOR(k,0,1) FOR(l,0,1){
  //      if(tn[i] && tn[j] && tm[k] && tm[l]){
    //        if(tn[i]+tn[j]+tm[k]+tm[l] == x) return true;
      //  }
   // }
    return x == n+m-2;
    return false;
}

inline int getqiang(int x,int y){
    if(x == 1) return 0;
    if(y == 1) return 1;
    if(x == n) return 2;
    if(y == m) return 3;
}

inline int chzt(int x,int qiang){
    if(qiang == 0){
         if(x == 0) return 3;
         if(x == 1) return 2;
    }
    if(qiang == 1){
        if(x == 1) return 0;
        if(x == 2) return 3;
    }
    if(qiang == 2){
        if(x == 3) return 0;
        if(x == 2) return 1;
    }
    if(qiang == 3){
        if(x == 0) return 1;
        if(x == 3) return 2;
    }
}

inline int chzt2(int x,int y){
    //if(x == 0) return 2;
    //if(x == 2) return 0;
    //if(x == 1) return 3;
    //if(x == 3) return 1;
    if(x == 1 && y == 1) return 3;
    if(x == 1 && y == m) return 2;
    if(x == n && y == 1) return 0;
    if(x == n && y == m) return 1;
}

inline void work(){int ts = 0;
    int x = sx,y = sy;int ans = 1;
    if(pd(x,y)){
        if(x == 1 && y == 1 && !vis[0][1] && !vis[1][1]) vis[0][1] = vis[1][1] = true,cnt += 1;
        if(x == 1 && y == m && !vis[0][m] && !vis[3][1]) vis[0][m] = vis[3][1] = true,cnt += 1;
        if(x == n && y == 1 && !vis[1][n] && !vis[2][1]) vis[1][n] = vis[2][1] = true,cnt += 1;
        if(x == n && y == m && !vis[2][m] && !vis[3][n]) vis[2][m] = vis[3][n] = true,cnt += 1;
     //   zt = chzt2(x,y);
    }
    else{
        int q = getqiang(x,y);
        if(q == 0 || q == 2) if(!vis[q][y]) vis[q][y] = true,cnt++;//,zt = chzt(zt,q);
        if(q == 1 || q == 3) if(!vis[q][x]) vis[q][x] = true,cnt++;//,zt = chzt(zt,q);
    }
    while(true){
        int k = getk(x,y,zt);int xx = x+dx[zt]*k,yy = y+dy[zt]*k;
        ans += k;ts++;
        //if(tss > 5) exit(0); //DEBUG message
        int q = getqiang(xx,yy);//DEBUG(cnt);
        //DEBUG(x);DEBUG(y);DEBUG(zt);DEBUG(k);
        // DEBUG(zt);DEBUG(xx);DEBUG(yy);
        if(pd(xx,yy)){
            zt = chzt2(xx,yy);
            if(ts == 1 && k == 0){
               // ans++;
               continue;
            }
            bool flag = false,flag2 = false;
            if(xx == 1 && yy == 1 && vis[0][1] && vis[1][1]) flag2 = true;
            if(xx == 1 && yy == m && vis[0][m] && vis[3][1]) flag2 = true;
            if(xx == n && yy == 1 && vis[1][n] && vis[2][1]) flag2 = true;
            if(xx == n && yy == m && vis[2][m] && vis[3][n]) flag2 = true;

            if(xx == 1 && yy == 1 && !vis[0][1] && !vis[1][1]) vis[0][1] = vis[1][1] = true,cnt += 1;
            if(xx == 1 && yy == m && !vis[0][m] && !vis[3][1]) vis[0][m] = vis[3][1] = true,cnt += 1;
            if(xx == n && yy == 1 && !vis[1][n] && !vis[2][1]) vis[1][n] = vis[2][1] = true,cnt += 1;
            if(xx == n && yy == m && !vis[2][m] && !vis[3][n]) vis[2][m] = vis[3][n] = true,cnt += 1;

            if(xx == 1 && yy == 1 && vis[0][2] && vis[1][2]) flag = true;
            if(xx == 1 && yy == m && vis[0][m-1] && vis[3][2]) flag = true;
            if(xx == n && yy == 1 && vis[1][n-1] && vis[2][2]) flag = true;
            if(xx == n && yy == m && vis[2][m-1] && vis[3][n-1]) flag = true;
            if(flag){
                puts("-1");exit(0);
            }
           // DEBUG(cnt);
            if(pdans(cnt)){
                printf("%lld\n",ans);exit(0);
            }
 /*           if(xx == 1 && yy == 1 && vis[0][1] && vis[1][1]) flag = true;
            if(xx == 1 && yy == m && vis[0][m] && vis[3][1]) flag = true;
            if(xx == n && yy == 1 && vis[1][n] && vis[2][1]) flag = true;
            if(xx == n && yy == m && vis[2][m] && vis[3][n]) flag = true;
   */       if(flag2){
                puts("-1");exit(0);
            }
        }
        else{
            //if(q == 0)
            int t = zt;
            zt = chzt(zt,q);
            assert(zt <= 3);assert(q <= 3);
            if(ts == 1 && k == 0){
                //ans++;
                continue;
            }
            bool flag = false;
            if(q == 0 || q == 2){ 
                if(!vis[q][yy]) {vis[q][yy] = true;cnt++;}
                if(!used[q][yy][t]) used[q][yy][t] = true;
                else{flag = true;}
            }
            if(q == 1 || q == 3){
                if(!vis[q][xx]) {vis[q][xx] = true,cnt++;}
                if(!used[q][xx][t]) used[q][xx][t] = true;
                else{flag = true;}
            }
            //if(!vis[xx][yy]) vis[xx][yy] = true,cnt++;
            if(pdans(cnt)){
                printf("%lld\n",ans);exit(0);
            }
            if(flag){
                puts("-1");exit(0);
            }
        }
        x = xx;y = yy;
    }
}

signed main(){
    scanf("%lld%lld%lld%lld",&n,&m,&sx,&sy);scanf("%s",str+1);
    if(str[1] == 'U' && str[2] == 'L') zt = 1;
    if(str[1] == 'D' && str[2] == 'L') zt = 2;
    if(str[1] == 'D' && str[2] == 'R') zt = 3;
    if(str[1] == 'U' && str[2] == 'R') zt = 0;
    /*tn[0] = n/2;tm[0] = m/2;
    if(n & 1) tn[1] = tn[0]+1;
    if(m & 1) tm[1] = tm[0]+1;*/
    //DEBUG(tn[0]);DEBUG(tn[1]);DEBUG(tm[0]);DEBUG(tm[1]);
    work();printf("%lld\n",ans);
    return 0;
}