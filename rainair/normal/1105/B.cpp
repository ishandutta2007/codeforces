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

#define fi first
#define se second
#define U unsigned
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2000000+5;
char str[MAXN];
int N,K;
int p[1000],ans[1111];

inline bool pd(){
    int cnt = 0;
    FOR(i,0,25) if(p[i]) cnt++;
   // FOR(i,0,25) printf("%d ",p[i]);puts("");
    return cnt == 1;
}

int main(){
    scanf("%d%d",&N,&K);
    scanf("%s",str+1);
    int now = 0;
    FOR(i,1,N){
        if(str[i] == str[i-1]) now++;
        else now = 1;
        if(now == K){
            ans[str[i] - 'a']++;
            now = 0;
        }
    }
    int rr = 0;
    FOR(i,0,26) rr = std::max(rr,ans[i]);
    printf("%d\n",rr);//system("pause");
    return 0;
}