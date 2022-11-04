#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int t[100005],pre[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+t[i];
    int l=0,r=n+1;
    while(l<r-1)
    {
        if(pre[l]<=pre[n]-pre[r-1])l++;
        else r--;
    }
    printf("%d %d\n",l,n+1-r);
    return 0;
}