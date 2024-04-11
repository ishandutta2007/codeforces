#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500005;
int res[MAXN<<1];
int main()
{
    int n;
    scanf("%d",&n);
    int now=1;
    for(int i=1,j=n;i<j;i++,j--)
    {
        res[i]=res[j]=now;
        now+=2;
    }
    now=2;
    for(int i=n+1,j=2*n-1;i<j;i++,j--)
    {
        res[i]=res[j]=now;
        now+=2;
    }
    res[2*n]=n;
    if(n&1)res[(n+1)/2]=n;
    else res[n+n/2]=n;
    for(int i=1;i<=2*n;i++)
        printf("%d ",res[i]);
    return 0;
}