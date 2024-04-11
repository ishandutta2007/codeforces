#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    bool flag=0;
    for(int i=0;i<=c/a;i++)
        if((c-i*a)%b==0)flag=1;
    printf("%s",(flag ? "Yes" : "No"));
    return 0;
}