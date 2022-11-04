#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int n,a[1005];
bool judge()
{
    for(int i=0;i<n;i++)
        if(a[i]!=i)return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    bool isok=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j%2==0)a[j]=(a[j]-1+n)%n;
            else a[j]=(a[j]+1)%n;
        }
        isok|=judge();
    }
    if(isok)printf("Yes\n");
    else printf("No\n");
    return 0;
}