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
// sss
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

const int MAXN = 2000 + 5;
int N,K;
char str[MAXN][MAXN];
int f[MAXN][MAXN],v[MAXN][MAXN];

int main(){
    scanf("%d%d",&N,&K);
    FOR(i,1,N) scanf("%s",str[i]+1);
    FOR(i,0,N) FOR(j,0,N) f[i][j] = INT_MAX;
    f[0][1]=0;
    FOR(i,1,N)
        FOR(j,1,N){
            f[i][j] = std::min(f[i-1][j],f[i][j-1]) + (str[i][j] != 'a');
            if(f[i][j] <= K) str[i][j] = 'a';
        }
    v[1][1]=1;
    FOR(i,2,2*N){
        char ch = 'z';
        int from = std::max(1,i-N);
        FOR(j,from,i-from)
            if(v[j][i-j]) ch = std::min(ch,str[j][i-j]);
        putchar(ch);
        FOR(j,from,i-from)
			if(v[j][i-j] && str[j][i-j] == ch) v[j][i-j+1] = v[j+1][i-j] = 1;
    }
    return 0;
}