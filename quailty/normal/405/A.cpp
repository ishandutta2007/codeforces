#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int t[105],ans[105];
int main()
{
    int n;
    scanf("%d",&n);
    int a;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(int j=1;j<=a;j++)
        {
            t[j]++;
        }
    }
    for(int i=1;i<=100;i++)
    {
        for(int j=n;j>n-t[i];j--)
        {
            ans[j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}