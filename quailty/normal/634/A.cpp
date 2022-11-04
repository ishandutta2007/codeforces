#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a[MAXN],b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    int ta,tb;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)ta=i;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]==1)tb=i;
    }
    for(int i=0;i<n;i++)
    {
        if(ta==n)ta-=n;
        if(tb==n)tb-=n;
        if(!a[ta])ta++;
        else if(!b[tb])tb++;
        else
        {
            if(a[ta]==b[tb])ta++,tb++;
            else return 0*printf("NO");
        }
    }
    printf("YES");
    return 0;
}