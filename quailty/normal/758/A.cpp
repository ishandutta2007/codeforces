#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[105],mx=0,res=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)
        res+=mx-a[i];
    return 0*printf("%d",res);
}