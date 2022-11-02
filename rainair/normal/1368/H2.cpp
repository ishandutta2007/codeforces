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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
// B = 0
// R = 1

struct DS{
    #define lc ((x)<<1)
    #define rc ((x)<<1|1)
    int f[4][MAXN<<2][2][2],rev[MAXN<<2];
    int a[MAXN][2],cnt[MAXN<<2][2],ext;
    DS(){CLR(f,0x3f);CLR(rev,0);CLR(a,0);CLR(cnt,0);ext=0;}
    // number of 0 both side 0:up/left 1:down/right

    inline void pushup(int x){
        FOR(a,0,3){
            CLR(f[a][x],0x3f);
            FOR(i,0,1){
                FOR(j,0,1){
                    FOR(k,0,1){
                        FOR(l,0,1){
                            f[a][x][i][j] = std::min(f[a][x][i][j],f[a][lc][i][k]+f[a][rc][l][j]+(k!=l)*ext);
                        }
                    }
                }
            }
        }
        FOR(i,0,1) cnt[x][i] = cnt[lc][i]+cnt[rc][i];
    }

    inline void build(int x,int l,int r){
        if(l == r){
            FOR(i,0,3){
                int cnt0 = (a[l][0]^(i&1))+(a[l][1]^((i>>1)&1)),cnt1 = 2-cnt0;
                f[i][x][0][0] = cnt1;
                f[i][x][1][1] = cnt0;
            }
            cnt[x][0] = a[l][0];cnt[x][1] = a[l][1];
            return;
        }
        int mid = (l + r) >> 1;
        build(lc,l,mid);build(rc,mid+1,r);
        pushup(x);
    }

    inline void reverse(int x,int l,int r,int d){
        rev[x] ^= d;
//        FOR(i,0,1) FOR(j,0,1) printf("%d ",f[0][x][i][j]);puts("");
        if(d == 1){
            std::swap(f[0][x],f[1][x]);
            std::swap(f[2][x],f[3][x]);
        }
        if(d == 2){
            std::swap(f[0][x],f[2][x]);
            std::swap(f[1][x],f[3][x]);
        }
        if(d == 3){
            std::swap(f[0][x],f[3][x]);
            std::swap(f[1][x],f[2][x]);
        }
        int len = r-l+1;
        if(d&1) cnt[x][0] = len-cnt[x][0];
        if(d&2) cnt[x][1] = len-cnt[x][1];
    }

    inline void pushdown(int x,int l,int r){
        if(rev[x]){
            int mid = (l + r) >> 1;
            reverse(lc,l,mid,rev[x]);reverse(rc,mid+1,r,rev[x]);
            rev[x] = 0;
        }
    }

    inline void modify(int x,int l,int r,int L,int R,int d){
        if(l == L && r == R){reverse(x,l,r,d);return;}
        int mid = (l + r) >> 1;pushdown(x,l,r);
        if(R <= mid) modify(lc,l,mid,L,R,d);
        else if(L > mid) modify(rc,mid+1,r,L,R,d);
        else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
        pushup(x);
    }
}LR,UD;

int n,m,q;
char U[MAXN],D[MAXN],L[MAXN],R[MAXN],opt[233];

inline int query(){
    int l[2],r[2],u[2],d[2];
    l[0] = LR.cnt[1][0];r[0] = LR.cnt[1][1];
    u[0] = UD.cnt[1][0];d[0] = UD.cnt[1][1];
    l[1] = n-l[0];r[1] = n-r[0];u[1] = m-u[0];d[1] = m-d[0];
    int ans = 1e9;
    FOR(i,0,1){
        FOR(j,0,1){
//            DEBUG(LR.f[0][1][i][j]);
            ans = std::min(ans,LR.f[0][1][i][j]+u[i^1]+d[j^1]);
            ans = std::min(ans,UD.f[0][1][i][j]+l[i^1]+r[j^1]);
        }
    }
    return ans;
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s%s%s%s",L+1,R+1,U+1,D+1);
    LR.ext = m;UD.ext = n;
    FOR(i,1,n) LR.a[i][0] = L[i]=='B',LR.a[i][1] = R[i]=='B';
    LR.build(1,1,n);
    FOR(i,1,m) UD.a[i][0] = U[i]=='B',UD.a[i][1] = D[i]=='B';
    UD.build(1,1,m);
//    DEBUG(UD.f[0][1][0][0]);
//    exit(0);
    printf("%d\n",query());
    FOR(i,1,q){
        int l,r;scanf("%s%d%d",opt,&l,&r);
        if(opt[0] == 'L'){
            LR.modify(1,1,n,l,r,1);
        }
        if(opt[0] == 'R'){
            LR.modify(1,1,n,l,r,2);
        }
        if(opt[0] == 'U'){
            UD.modify(1,1,m,l,r,1);
        }
        if(opt[0] == 'D'){
            UD.modify(1,1,m,l,r,2);
        }
        printf("%d\n",query());
    }
    return 0;
}