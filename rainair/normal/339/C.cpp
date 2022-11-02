#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int M;
char str[sizeof("111111111111111")];
int b[15],cnt;
int ans[1000000];

bool dfs(int num,int last,int step){
    if(step == M + 1) return 1;
    FOR(i,1,cnt){
        if(b[i] > num && b[i] != last){
            if(dfs(b[i]-num,b[i],step + 1)){
                ans[step] = b[i];
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%s",str + 1);
    scanf("%d",&M);
    FOR(i,1,10){
        if(str[i] == '1') b[++cnt] = i;
    }
    if(dfs(0,0,1)){
        puts("YES");
        FOR(i,1,M) printf("%d ",ans[i]);
    }
    else puts("NO");
    return 0;
}