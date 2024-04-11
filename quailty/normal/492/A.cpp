#include<cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    while(n>=0){
        i++;
        n-=i*(i+1)/2;
    }
    i--;
    printf("%d\n",i);
    return 0;
}