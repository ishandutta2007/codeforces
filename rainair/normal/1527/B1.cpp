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

const int MAXN = 1e3 + 5;
char str[MAXN];
int n;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,str+1);
        int s = 0;
        FOR(i,1,n) s += (str[i]=='0');
        if(n&1 && ((str[n/2+1]) == '0') && s > 1){
            puts("ALICE");
        }
        else{
            puts("BOB");
        }
    }
    return 0;
}