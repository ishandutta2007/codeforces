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
int n,m,a[MAXN][MAXN],b[MAXN][MAXN];
bool r[MAXN*MAXN],c[MAXN*MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(i,1,n){
        int mx = 0;
        FOR(j,1,m) mx = std::max(mx,a[i][j]);
        r[mx] = 1;
    }
    FOR(j,1,m){
        int mx = 0;
        FOR(i,1,n) mx = std::max(mx,a[i][j]);
        c[mx] = 1;
    }
    int R = 0,C = 0;std::queue<P<int,int> > q;
    ROF(i,n*m,1){
        if(!r[i] && !c[i]){
            b[q.front().fi][q.front().se] = i;
            q.pop();
            continue;
        }
        if(r[i]) ++R;
        if(c[i]) ++C;
        b[R][C] = i;
        if(r[i]) ROF(i,C-1,1) q.push(MP(R,i));
        if(c[i]) ROF(i,R-1,1) q.push(MP(i,C));
    }
    FOR(i,1,n) FOR(j,1,m) printf("%d%c",b[i][j]," \n"[j==m]);
    return 0;
}