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

const int MAXN = 1000+5;
char str[MAXN];
int n;
const char biao1[] = {'A','H','I','M','O','o','T','U','V','v','W','w','X','x','Y'};
bool vis[256+5];

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,0,14) vis[biao1[i]] = 1;
    bool flag = 1;
    if(n&1) flag &= vis[str[(n+1)>>1]];
    FOR(i,1,n/2){
        char x = str[i],y = str[n-i+1];
        if(x > y) std::swap(x,y);
        if(x == 'b' && y == 'd') continue;
        if(x == 'p' && y == 'q') continue;
        if(x == y && vis[x]) continue;
        flag = 0;
    }
    puts(flag?"TAK":"NIE");
    return 0;
}