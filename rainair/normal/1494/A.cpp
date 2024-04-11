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

const int MAXN = 50+5;
char s[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);int n = strlen(s+1);
        bool ans = 0;
        FOR(S,0,(1<<3)-1){
            int now = 0;bool flag = 1;
            FOR(i,1,n){
                int c = (S>>(s[i]-'A'))&1 ? -1 : 1;
                now += c;
                if(now < 0){
                    flag = 0;break;
                }
            }
            flag &= (now==0);
            if(flag){ans = 1;break;}
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}