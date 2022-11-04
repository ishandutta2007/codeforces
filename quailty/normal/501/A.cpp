#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int m=max(3*a/10,a-a/250*c);
    int v=max(3*b/10,b-b/250*d);
    if(m>v)printf("Misha\n");
    else if(m<v)printf("Vasya\n");
    else printf("Tie\n");
    return 0;
}