#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#define mo 1000000007
#define eps 1e-8
using namespace std;
int t,n,m,a[100],ans;
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&m);
        ans=(ans+m-1)%2;
        if (ans==1) printf("1\n");
        else printf("2\n");
    }
    return 0;
}