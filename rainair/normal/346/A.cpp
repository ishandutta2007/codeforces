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
#define RFOR(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100 + 5;
int N;
int a[MAXN];

int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}

int main(){
    scanf("%d",&N);
    FOR(i,1,N) scanf("%d",a+i);
    std::sort(a + 1,a + N + 1);
    int k = a[1];
    FOR(i,2,N) k = gcd(k,a[i]);
    int ans = a[N]/k - N;
    if(ans & 1) puts("Alice");
    else puts("Bob");
    return 0;
}