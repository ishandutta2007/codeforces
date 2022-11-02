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

const int MAXN = 2e5 + 5;
char s[MAXN];int n;
char a[MAXN],b[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int c = 0;FOR(i,1,n) c += (s[i] == '0');
        if(s[1] == '0' || s[n] == '0' || (c&1)){
            puts("NO");
            continue;
        }
        puts("YES");
        int now = 0,all = (n-c)>>1;
        FOR(i,1,n){
            if(s[i] == '0'){
                if(now) a[i] = '(',b[i] = ')';
                else a[i] = ')',b[i] = '(';
                now ^= 1;
            }
            else{
                if(all) a[i] = b[i] = '(',--all;
                else a[i] = b[i] = ')';
            }
        }
        FOR(i,1,n) putchar(a[i]);puts("");
        FOR(i,1,n) putchar(b[i]);puts("");
    }
    return 0;
}