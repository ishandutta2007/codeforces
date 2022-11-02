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

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((a + b + c) & 1) puts("Impossible");
    else{
        int x = (a + b - c)/2;
        int y = a-x,z = b-x;
        if(x<0 or y < 0 or z < 0){
            puts("Impossible");
        }
        else{
            printf("%d %d %d\n",x,z,y);
        }
    }
    return 0;
}