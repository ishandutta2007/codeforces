#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 250 + 5;
int a[MAXN][MAXN],n,m;char s[MAXN];
bool vis[MAXN][MAXN];
int bel[MAXN][MAXN];
int cnt,ts;
int mnx,mny,mxx,mxy;

inline void dfs(int x,int y){
    vis[x][y] = 1;++cnt;bel[x][y] = ts;
    mnx = std::min(mnx,x);
    mxx = std::max(mxx,x);
    mny = std::min(mny,y);
    mxy = std::max(mxy,y);
    FOR(dx,-1,1){
        FOR(dy,-1,1){
            if(!dx && !dy) continue;
            int xx = x+dx,yy = y+dy;
            if(xx < 1 || xx > n || yy < 1 || yy > m || !a[xx][yy] || vis[xx][yy]) continue;
            dfs(xx,yy);
        }
    }
}

inline void Solve(){
    scanf("%d%d",&n,&m);ts = 0;
    FOR(i,1,n){
        scanf("%s",s+1);
        FOR(j,1,m){
            a[i][j] = s[j]-'0';
            vis[i][j] = 0;bel[i][j] = 0;
        }
    }
    int ans = 0;
    FOR(i,1,n){
        FOR(j,1,m){
            if(!a[i][j] || vis[i][j]) continue;
            cnt = 0;
            mxx = mnx = i;
            mxy = mny = j;++ts;
            dfs(i,j);
            if(cnt <= 1) continue;
            if(mxx-mnx != mxy-mny) continue;
            bool flag;
            if(bel[mnx][mny] == ts && bel[mxx][mxy] == ts){
                flag = (cnt==4*(mxx-mnx));
                FOR(i,mnx,mxx) flag &= a[i][mny]&a[i][mxy];
                FOR(i,mny,mxy) flag &= a[mnx][i]&a[mxx][i];
            }
            else{
                flag = (cnt==2*(mxx-mnx))&&(mxx-mnx >= 2)&&(mxy-mny >= 2);
                int midx = (mxx+mnx)/2,midy = (mxy+mny)/2;
                auto pd = [&](int x1,int y1,int x2,int y2){
                    bool flag = 1;
                    if(x1+y1 == x2+y2){
                        FOR(i,x1,x2) flag &= a[i][x1+y1-i];
                    }
                    else{// -y=x1-y1-x
                        FOR(i,x1,x2) flag &= a[i][i+y1-x1];
                    }
                    return flag;
                };
                flag &= pd(mnx,midy,midx,mny)&pd(mnx,midy,midx,mxy)&pd(midx,mny,mxx,midy)&pd(midx,mxy,mxx,midy);
            }
            ans += flag;
        }
    }
    printf("%d\n",ans);
}

int main(){
//    freopen("B.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}