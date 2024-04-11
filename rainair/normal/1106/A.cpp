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
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 500+5;
char str[MAXN][MAXN];
int N;int ans = 0;

int main(){
    scanf("%d",&N);
    FOR(i,1,N){
        scanf("%s",str[i]+1);
    }
    FOR(i,1,N){
        FOR(j,1,N){
            if(str[i][j] == 'X' && str[i-1][j-1] == 'X' && str[i-1][j+1] == 'X' && str[i+1][j-1] == 'X' && str[i+1][j+1] == 'X') ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}