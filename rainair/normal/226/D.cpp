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
#define P std::pair<int,int>
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
int a[MAXN][MAXN],l1[MAXN],l2[MAXN];
int n,m;
int d1[MAXN],d2[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]),l1[i] += a[i][j],l2[j] += a[i][j];
    int flag = true;
    while(flag){
        flag = false;int pos1 = 0,pos2 = 0;
        FOR(i,1,n) if(l1[i] < 0) pos1 = i;
        FOR(i,1,m) if(l2[i] < 0) pos2 = i;
        if(!pos1 && !pos2) break;
        flag = true;
        if(pos1){ // heng
            l1[pos1] = -l1[pos1];
            FOR(i,1,m) l2[i] -= a[pos1][i],a[pos1][i] = -a[pos1][i],l2[i] += a[pos1][i];
            d1[pos1]++;
        }
        else{ // zong
            l2[pos2] = -l2[pos2];
            FOR(i,1,n) l1[i] -= a[i][pos2],a[i][pos2] = -a[i][pos2],l1[i] += a[i][pos2];
            d2[pos2]++;
        }
    }
    int cnt = 0;
    FOR(i,1,n) if(d1[i]&1) cnt++;printf("%d ",cnt);
    FOR(i,1,n) if(d1[i]&1) printf("%d ",i);puts("");
    cnt = 0;FOR(i,1,m) if(d2[i]&1) cnt++;printf("%d ",cnt);
    FOR(i,1,m) if(d2[i]&1) printf("%d ",i);puts("");
    return 0;
}