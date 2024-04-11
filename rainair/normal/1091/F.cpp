#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100000+5;
LL l[MAXN],N;
char str[MAXN];
LL ans = 0,power = 0,grass = 0;
bool water = false;

int main(){
    scanf("%I64d",&N);
    FOR(i,1,N) scanf("%I64d",l+i);
    scanf("%s",str+1);
    FOR(i,1,N){
        if(str[i] == 'L'){
            ans += l[i];
            power -= l[i];
            if(power < 0){
                ans -= power * (water ? 3 : 5);
                power = 0;
            }
        }
        if(str[i] == 'W'){
            water = true;
            power += l[i];
            ans += l[i]*3;
        }
        if(str[i] == 'G'){
            power += l[i];
            ans += l[i]*5;
            grass += (l[i]<<1);
        }
        grass = std::min(grass,power);
    }
    if(power > 0){
        ans -= 4*grass/2;
        ans -= 2*(power-grass)/2;
    }
    printf("%I64d\n",ans);
    return 0;
}