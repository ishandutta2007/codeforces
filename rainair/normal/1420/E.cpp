#include <bits/stdc++.h>

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

const int MAXN = 80+5;
int a[MAXN],n;
int f[MAXN][MAXN][MAXN*MAXN];
// i   j  1  k

inline void upmin(int &x,int y){
    if(x > y) x = y;
}
// 
int x[MAXN];
int main(){
    scanf("%d",&n);int m = 0;
    FOR(i,1,n){
        scanf("%d",a+i);
        if(a[i]) x[++m] = i;
    }
    int all = (n-m)*(n-m-1)/2;
    int lim = n*(n-1)/2;
    if(!m){
        FOR(i,0,lim) printf("%d ",0);
        puts("");exit(0);
    }
    CLR(f,0x3f);
    f[0][0][0] = 0;
    FOR(i,0,n-1){
        FOR(j,0,std::min(m-1,i)){
            FOR(k,0,lim){
                if(f[i][j][k] == 0x3f3f3f3f) continue;
                FOR(l,i+1,n){
                    int len = l-i-1,gx = 0;
                    if(j == 0) gx = i*(i-1)/2;
                    upmin(f[l][j+1][k+std::abs(x[j+1]-l)],f[i][j][k]+len*(len-1)/2+gx);
                }
            }
        }
    }
    FOR(i,1,n) FOR(j,0,lim) upmin(f[i][m][j],f[i][m][j-1]);
    FOR(i,0,lim){
        int ans = 1e9;
        FOR(j,0,n) upmin(ans,f[j][m][i]+(n-j)*(n-j-1)/2);
        printf("%d ",all-ans);
    }
    puts("");
    return 0;
}