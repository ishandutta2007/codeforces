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

const int MAXN = 10 + 5;

int v,min=INT_MAX,a[MAXN],N;

int main(){
    scanf("%d",&v);
    FOR(i,1,9){
        scanf("%d",a+i);
        min=std::min(min,a[i]);
    }
    if(min > v){
        puts("-1");return 0;
    }
    RFOR(i,v/min,1){
        RFOR(j,9,1){
            if(v >= a[j] && (v-a[j])/min+1 >= i){
                printf("%d",j);
                v -= a[j];
                break;
            }
        }
    }
    return 0;
}