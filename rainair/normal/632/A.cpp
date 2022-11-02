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

const int MAXN = 40+5;
int n,p;
char str[23];
int a[MAXN];

int main(){
    scanf("%d%d",&n,&p);
    FOR(i,1,n){
        scanf("%s",str+1);int len = strlen(str+1);
        a[i] = (len==8);
    }
    LL total = 0,s = 0;
    ROF(i,n,1){
        total |= a[i];total <<= 1;
        s += (total>>1);
    }
    p /= 2;
    printf("%lld\n",s*p);
    return 0;
}