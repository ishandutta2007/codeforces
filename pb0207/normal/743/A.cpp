#include<stdio.h>
#include<string.h>
char map[200000];
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",map);
    if(map[a-1]==map[b-1])
    printf("0\n");
    else
    printf("1\n");
}