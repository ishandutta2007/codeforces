#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=1,now=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])now++;
        else now=1;
        res=max(res,now);
    }
    return 0*printf("%d",res);
}