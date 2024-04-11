#include <iostream>
#include <cstring>
#include <cstdio>

#define LL long long
LL sum1,sum2;
int N;

int main(){
    scanf("%d",&N);
    for(int x,i = 1;i <= N;i++){
        scanf("%d",&x);
        sum1 += x;
    }
    for(int x,i = 1;i <= N;i++){
        scanf("%d",&x);
        sum2 += x;
    }
    if(sum2 > sum1) puts("No");
    else puts("Yes");
    return 0;
}