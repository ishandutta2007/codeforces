#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
int a[MAXN],b[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+k+1,greater<int>());
    for(int i=1,j=1;i<=n;i++)
        if(!a[i])a[i]=b[j++];
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1])return 0*printf("Yes");
    return 0*printf("No");
}