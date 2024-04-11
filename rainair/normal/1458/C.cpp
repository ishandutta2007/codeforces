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

const int MAXN = 1000+5;
int a[MAXN][MAXN],n,m,b[MAXN][MAXN];
int id[4],d[4];
char str[100000+5];

inline void Solve(){
    scanf("%d%d",&n,&m);
    FOR(i,0,n-1) FOR(j,0,n-1) scanf("%d",&a[i][j]),--a[i][j];
    scanf("%s",str+1);CLR(d,0);
    FOR(i,1,3) id[i] = i;
    FOR(i,1,m){
        if(str[i] == 'R'){
            d[id[2]]++;
        }
        if(str[i] == 'L'){
            d[id[2]]--;
        }
        if(str[i] == 'U'){
            d[id[1]]--;
        }
        if(str[i] == 'D'){
            d[id[1]]++;
        }
        if(str[i] == 'I'){
            std::swap(id[2],id[3]);
        }
        if(str[i] == 'C'){
            std::swap(id[1],id[3]);
        }
    }
    FOR(i,0,n-1){
        FOR(j,0,n-1){
            int x=0,y=0,z=0;
            FOR(k,1,3){
                int t = 0;
                if(k == 1) t = i;
                if(k == 2) t = j;
                if(k == 3) t = a[i][j];
                (t += d[k]%n+n) %= n;
                if(id[1] == k) x = t;
                if(id[2] == k) y = t;
                if(id[3] == k) z = t;
            }
            b[x][y] = z;
        }
    }
    FOR(i,0,n-1) FOR(j,0,n-1) printf("%d%c",b[i][j]+1," \n"[j==n-1]);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}