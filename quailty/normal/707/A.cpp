#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    bool isok=0;
    for(int i=1;i<=n*m;i++)
    {
        char c[5];
        scanf("%s",c);
        if(*c!='W' && *c!='B' && *c!='G')isok=1;
    }
    if(!isok)printf("#Black&White");
    else printf("#Color");
    return 0;
}