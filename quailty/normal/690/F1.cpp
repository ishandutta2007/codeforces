#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int d[10005];
int main()
{
    int n,res=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        d[a]++;
        d[b]++;
    }
    for(int i=1;i<=n;i++)
        res+=d[i]*(d[i]-1)/2;
    printf("%d\n",res);
    return 0;
}