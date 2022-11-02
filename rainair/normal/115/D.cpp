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

const int MAXN = 2000+5;
const int ha = 1e6 + 3;

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

char str[MAXN];
int a[MAXN],n;
int f[2][MAXN],now;
int sm[MAXN];

int main(){
    scanf("%s",str+1);int len = strlen(str+1);
    FOR(i,1,len){
        if(str[i] == '+' || str[i] == '-') a[++n] = 1;
        else if(str[i] == '*' || str[i] == '/') a[++n] = 2;
        else{
            a[++n] = 0;
            while(isdigit(str[i])) ++i;--i;
        }
    }
    if(a[1]==2 || a[n]){
        puts("0");
        return 0;
    }
    for(int l = 1,r = 1;l <= n;l = r+1){
        r = l;if(!a[l]) continue;
        while(r+1 <= n && a[r]) ++r;
        FOR(i,l+1,r) if(a[i] == 2){
            puts("0");
            return 0;
        }
    }
    f[now=0][0] = 1;
    FOR(i,1,n){
        CLR(f[now^1],0);
        if(a[i] == 0) continue;
        if(a[i+1] == 0){
            ROF(j,n,0) add(f[now][j],f[now][j+1]);
            FOR(j,0,n) f[now^1][j] = f[now][std::max(0,j-1)];
        }
        else{
            FOR(j,1,n) f[now^1][j] = f[now][j-1];
        }
        now ^= 1;
    }
    printf("%d\n",f[now][0]);
    return 0;
}