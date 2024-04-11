#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int l=2*n+1,r=1;
    while(r<=min(2*n,m))
    {
        if(l<=m)printf("%d ",l++);
        printf("%d ",r++);
    }
    return 0;
}