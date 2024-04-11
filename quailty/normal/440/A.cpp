#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,t=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        t^=i;
    for(int i=1;i<=n-1;i++)
    {
        int a;
        scanf("%d",&a);
        t^=a;
    }
    return 0*printf("%d",t);
}