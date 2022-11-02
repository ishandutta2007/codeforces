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

int n,k;
char str[114514];
int len;

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,0,k-1){
        str[len++] = 'a'+i;
        FOR(j,i+1,k-1){
            str[len++] = 'a'+i;
            str[len++] = 'a'+j;
        }
    }
    FOR(i,1,n) putchar(str[i%len]);puts("");
    return 0;
}