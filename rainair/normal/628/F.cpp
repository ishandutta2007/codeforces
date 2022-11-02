#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;

int n,b,q;
int a[MAXN],t[5];
int c[MAXN][5],tot,r[MAXN];

int main(){
    scanf("%d%d%d",&n,&b,&q);
    CLR(a,-1);a[0] = 0;
    FOR(i,1,q){
        int lim,num;scanf("%d%d",&lim,&num);
        if(a[lim] != -1 && a[lim] != num){
            puts("unfair");
            return 0;
        }
        a[lim] = num;
    }
    int las = 0;
    if(a[b] == -1) a[b] = n;
    else{
        if(a[b] != n){
            puts("unfair");
            return 0;
        }
    }
    FOR(i,1,b){
        if(a[i] == -1) continue;
        if(a[las] > a[i] || a[i]-a[las] > i-las){
            puts("unfair");
            return 0;
        }
        // [las+1,i]  a[i] 
        ++tot;r[tot] = a[i]-a[las];
        FOR(k,las+1,i) ++c[tot][k%5];
        las = i;
    }
    FOR(S,1,(1<<5)-1){
        int sm = 0;
        FOR(i,1,tot){
            int t = 0;
            FOR(j,0,4) if((S>>j)&1) t += c[i][j];
            t = std::min(t,r[i]);
            sm += t;
        }
        if(sm < __builtin_popcount(S)*n/5){
            puts("unfair");
            return 0;
        }
    }
    puts("fair");
    return 0;
}