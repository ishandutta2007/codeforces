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

const int MAXN = 200+5;
int N;
int a[MAXN];
int vote[MAXN];
bool ok=false;
const int ha = 360;

void dfs(int step){
    if(ok) return;
    if(step == N+1){
        int cnt = 0;
        FOR(i,1,N) cnt = (cnt + a[i]*vote[i]+ha)%ha;
        if(!cnt){
            ok = true;
        }
        return;
    }
    vote[step] = 1;
    dfs(step+1);
    vote[step] = -1;
    dfs(step+1);
}

int main(){
    scanf("%d",&N);
    FOR(i,1,N) scanf("%d",a+i);
    dfs(1);
    puts(ok ? "YES" : "NO");
    return 0;
}