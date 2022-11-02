#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
    int n,h;
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>h)res+=2;
        else res+=1;
    }
    return 0*printf("%d",res);
}