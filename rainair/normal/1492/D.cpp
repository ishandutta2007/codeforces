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

const int MAXN = 5e5 + 5;
int s[MAXN],t[MAXN];

int main(){
    int a,b,k;scanf("%d%d%d",&a,&b,&k);
    if(!a){
        if(k){
            puts("No");
            return 0;
        }
        puts("Yes");
        FOR(i,1,b) putchar('1');puts("");
        FOR(i,1,b) putchar('1');puts("");
        return 0;
    }
    if(b == 1){
        if(k){
            puts("No");
            return 0;
        }
        puts("Yes");
        putchar('1');FOR(i,1,a) putchar('0');puts("");
        putchar('1');FOR(i,1,a) putchar('0');puts("");
        return 0;
    }
    if(k > a+b-2){
        puts("No");
        return 0;
    }
    int n = a+b;
    s[1] = t[1] = 1;
    s[2] = t[2+k] = 1;
    b -= 2;
    for(int i = 3;b;i++){
        if(s[i] || t[i]) continue;
        --b;s[i] = t[i] = 1;
    }
    puts("Yes");
    FOR(i,1,n) printf("%d",s[i]);puts("");
    FOR(i,1,n) printf("%d",t[i]);puts("");
    return 0;
}