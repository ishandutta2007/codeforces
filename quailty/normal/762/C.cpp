#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char a[100005],b[100005];
int l[100005],r[100005];
int main()
{
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1);
    for(int i=0;i<=m+1;i++)
        l[i]=n+1,r[i]=0;
    l[0]=0;
    for(int i=1,j=1;i<=n;i++)
    {
        if(j<=m && a[i]==b[j])j++;
        l[j-1]=min(l[j-1],i);
    }
    r[m+1]=n+1;
    for(int i=n,j=m;i>=1;i--)
    {
        if(j>=1 && a[i]==b[j])j--;
        r[j+1]=max(r[j+1],i);
    }
    int res_l=0,res_r=m+1;
    for(int i=0,j=0;i<=m;i++)
    {
        while(j<=i || r[j]<=l[i])j++;
        if(j-i<res_r-res_l)res_l=i,res_r=j;
    }
    if(res_l==0 && res_r==m+1)printf("-");
    else
    {
        for(int i=1;i<=res_l;i++)
            printf("%c",b[i]);
        for(int i=res_r;i<=m;i++)
            printf("%c",b[i]);
    }
    return 0;
}