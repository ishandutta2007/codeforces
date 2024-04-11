#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
int ask(int i,int j)
{
    printf("? %d %d\n",i,j);
    fflush(stdout);
    int res;
    scanf("%d",&res);
    return res;
}
int a[MAXN];
int main()
{
    int n,s[4];
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
        s[i]=ask(i,i%3+1);
    int t=(s[1]+s[2]+s[3])/2;
    for(int i=1;i<=3;i++)
        a[i]=t-s[i%3+1];
    for(int i=4;i<=n;i++)
        a[i]=ask(1,i)-a[1];
    printf("!");
    for(int i=1;i<=n;i++)
        printf(" %d",a[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}