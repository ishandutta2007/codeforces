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

const int MAXN = 1e5 + 5;
char s[MAXN];int n,x,y;
LL a[MAXN],b[MAXN];

int main(){
    scanf("%s",s+1);n = strlen(s+1);
    scanf("%d%d",&x,&y);
    LL p0=0,p1=0,s0=0,s1=0;
    FOR(i,1,n) s0 += (s[i]=='0'),s1 += (s[i]=='1');
    LL sm = 0;
    FOR(i,1,n){
        s0 -= (s[i]=='0');s1 -= (s[i]=='1');
        if(s[i] != '?'){
            if(s[i] == '0') sm += y*p1+x*s1;
            if(s[i] == '1') sm += y*s0+x*p0;
        }
        p0 += (s[i]=='0');p1 += (s[i]=='1');
        if(s[i] == '?'){
            a[i] = y*p1+x*s1;
            b[i] = x*p0+y*s0;
        }
    }
    LL ans = 1e18;
    LL pc=0,sc=0;
    FOR(i,1,n) sc += (s[i]=='?');
    LL pa=0,pb=0,sa=0,sb=0;
    FOR(i,1,n) sa += a[i],sb += b[i];
    ans = std::min(ans,sb);
    FOR(i,1,n){
        if(s[i] == '?'){
            ++pc;--sc;
            pa += a[i];pb += b[i];
            sa -= a[i];sb -= b[i];
            ans = std::min(ans,pc*sc*x+pa+sb);
            ans = std::min(ans,pc*sc*y+pb+sa);
        }
    }
    sm >>= 1;
    printf("%lld\n",ans+sm);
    return 0;
}