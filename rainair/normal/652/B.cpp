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
int a[MAXN],ans[MAXN],n;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    std::sort(a+1,a+n+1);int t = 1;
    for(int i = 1;i <= n;i += 2) ans[i] = a[t++];
    for(int i = 2;i <= n;i += 2) ans[i] = a[t++];
    FOR(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}