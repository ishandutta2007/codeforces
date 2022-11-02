#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
const int MAXN = 100+5;
int n,p,q;
char str[MAXN];

int main(){
    scanf("%d%d%d",&n,&p,&q);
    scanf("%s",str+1);
    int ans = 0;
    FOR(i,0,n){
        if(i*p > n) break;
        if((n-i*p)%q) continue;
        int p1 = i,p2 = (n-i*p)/q;
        printf("%d\n",p1+p2);
        int t = 1;
        FOR(i,1,p1){
            FOR(j,1,p) putchar(str[t++]);
            puts("");
        }
        FOR(i,1,p2){
            FOR(j,1,q) putchar(str[t++]);
            puts("");
        }
        return 0;
    }
    puts("-1");
    return 0;
}