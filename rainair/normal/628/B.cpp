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

const int MAXN = 3e5 + 5;
char str[MAXN];int n;

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    LL ans = 0;
    FOR(i,1,n) if(str[i] == '0' || str[i]=='4'||str[i]=='8') ++ans;
    FOR(i,2,n){
        int x = (str[i-1]-'0')*10+str[i]-'0';
        if(!(x%4)) ans += i-1;
    }
    printf("%lld\n",ans);
    return 0;
}