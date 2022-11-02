#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#define mo 1000000007
#define eps 1e-8
using namespace std;
int t,n,m,a[100],dp[100],ans;
int main()
{
    scanf("%d",&n);
    int tmp=0;
    for (int i=0;i<n-1;i++)
    {
        if (!tmp) printf("I hate that ");
        else printf("I love that ");
        tmp=tmp^1;
    }
    if (!tmp) printf("I hate it");
    else printf("I love it");
    return 0;
}