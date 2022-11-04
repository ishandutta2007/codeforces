#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1,j=n;i<j;i++,j--)
        if(i&1)swap(a[i],a[j]);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}