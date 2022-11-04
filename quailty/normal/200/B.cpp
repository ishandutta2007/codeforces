#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        sum+=p;
    }
    printf("%.12f\n",1.0*sum/n);
    return 0;
}