#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int t[4],a[100005];
int main()
{
    for(int i=0;i<4;i++)
        scanf("%d",&t[i]);
    int d;
    scanf("%d",&d);
    for(int i=0;i<4;i++)
        for(int j=0;j<=d;j+=t[i])
            a[j]=1;
    int res=0;
    for(int i=1;i<=d;i++)
        res+=a[i];
    return 0*printf("%d",res);
}