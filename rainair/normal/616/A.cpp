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

const int MAXN = 1e6 + 5;
char a[MAXN],b[MAXN];
int n,m;

int main(){
    scanf("%s%s",a+1,b+1);
    n = strlen(a+1);m = strlen(b+1);
    std::reverse(a+1,a+n+1);
    std::reverse(b+1,b+m+1);
    while(n > 1 && a[n] == '0') --n;
    while(m > 1 && b[m] == '0') --m;
    if(n < m){
        puts("<");
        return 0;
    }
    if(n > m){
        puts(">");
        return 0;
    }
    ROF(i,n,1){
        if(a[i] < b[i]){
            puts("<");
            return 0;
        }
        if(a[i] > b[i]){
            puts(">");
            return 0;
        }
    }
    puts("=");
    return 0;
}