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
int p[3][MAXN*10];
char str[MAXN*10];
int N,ans;
int main(){
    scanf("%d",&N);
    FOR(i,1,N){
        scanf("%s",str+1);
        int now = 0,t = 0;
        bool flag1 = 0,flag2 = 0;
        int len = strlen(str+1);
        FOR(j,1,len){
            if(str[j] == '(') now++;
            else now--;
            if(now < 0) flag1 = true; 
        }
        t = -now;now = 0;
        ROF(j,len,1){
            if(str[j] == ')') now++;
            else now--;
            if(now < 0)flag2 = true;
        }
        if(flag1 && flag2) continue;
        if(flag1){
            if(p[2][t]){
                p[2][t]--;
                ans++;
            }
            else p[1][t]++;
        }
        else if(flag2){
            if(p[1][-now]){
                p[1][-now]--;
                ans++;
            }
            else p[2][-now]++;
        }
        else{
            if(p[0][0]){
                p[0][0]--;
                ans++;
            }
            else p[0][0]++;
        }
    }
    printf("%d\n",ans);
    return 0;
}