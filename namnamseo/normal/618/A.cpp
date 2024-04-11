#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=31;0<=i;--i){
        if(1&(n>>i)) printf("%d ",i+1);
    }
    return 0;
}