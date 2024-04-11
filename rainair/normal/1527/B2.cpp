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
        int s = 0,r = 0;
        FOR(i,1,n) r += (str[i] != str[n-i+1]);
        r >>= 1;
        FOR(i,1,n) s += (str[i]=='0' && str[n-i+1] == '0');
        if(s == 0){
            if(r == 0) puts("DRAW");
            else puts("ALICE");
            continue;
        }
        if(n&1 && ((str[n/2+1]) == '0')){
            if(s == 1){
                if(r == 0){
                    puts("BOB");
                }
                else if(r == 1){
                    puts("DRAW");
                }
                else puts("ALICE");
                // BOB  1 
            }
            else{
                // ALICE  1 
                puts("ALICE");
            }
        }
        else{
            // BOB  2 
            if(r == 0) puts("BOB");
            else if(r == 1) puts("ALICE");// ALICEr,
            else if(r == 2) puts("ALICE");// 1. 2.r 
            else puts("ALICE");
        }
    }
    return 0;
}