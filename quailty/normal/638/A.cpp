#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,a;
    scanf("%d%d",&n,&a);
    if(a&1)printf("%d",(a+1)/2);
    else printf("%d",(n+2-a)/2);
    return 0;
}