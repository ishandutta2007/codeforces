#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        b[i]=b[i-1]+a;
    }
    int res=0;
    for(int i=1;i<n;i++)
        res+=(2*b[i]==b[n]);
    printf("%d",res);
    return 0;
}