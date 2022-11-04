#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    if(n%4>=2)return 0*printf("-1");
    for(int i=1,j=n;i<j;i+=2,j-=2)
    {
        res[i]=i+1;
        res[i+1]=j;
        res[j]=j-1;
        res[j-1]=i;
    }
    if(n%4==1)res[(n+1)/2]=(n+1)/2;
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}