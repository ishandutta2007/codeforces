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

const int MAXN = 100 + 5;
char str[MAXN];int n;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);n = strlen(str+1);
        bool ok = 0;
        FOR(i,0,n){// [1,i] & [i+1,n]
            int las = -1;bool flag = 1;
            FOR(j,1,i){
                if(str[j] == '1') flag &= las != j-1,las = j;
            }
            FOR(j,i+1,n){
                if(str[j] == '0') flag &= las != j-1,las = j;
            }
            if(flag){
                puts("YES");ok = 1;
                break;
            }
        }
        if(!ok) puts("NO");
    }
    return 0;
}