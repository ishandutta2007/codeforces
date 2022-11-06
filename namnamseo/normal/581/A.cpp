#include <cstdio>

int min(int a,int b){ return a>b?b:a; }

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d\n",min(a,b),(a+b)/2-min(a,b));
    return 0;
}