#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(a[1]==0)return 0*printf("-1\n");
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i]-1;
    if(sum<-1)return 0*printf("-1\n");
    printf("%d\n",n-1);
    int la=1;
    for(int i=2;i<=n;i++)
        if(a[i]>0)
        {
            printf("%d %d\n",la,i);
            la=i;
        }
    for(int i=1,j=1;i<=n;i++)
        for(int k=0;j<=n && k<a[i]-(i!=la);k++)
        {
            while(j<=n && a[j])j++;
            if(j<=n)printf("%d %d\n",i,j++);
        }
    return 0;
}