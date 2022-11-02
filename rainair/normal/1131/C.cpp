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

#define int LL
const int MAXN = 100000+5;
int N;
int a[MAXN],b[MAXN];

signed main(){
    scanf("%I64d",&N);
    FOR(i,1,N) scanf("%I64d",a+i);
    std::sort(a+1,a+N+1);
    int i = 1,j = N,opt = 0;
    FOR(k,1,N){
        if(opt == 0){
            b[i++] = a[k];
        }
        else{
            b[j--] = a[k];
        }
        opt ^= 1;
    }
    FOR(i,1,N) printf("%I64d ",b[i]);
    return 0;
}