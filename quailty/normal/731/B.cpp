#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        if(a[i]&1)a[i]--,a[i+1]--;
    for(int i=1;i<=n;i++)
        if(a[i]<0 || a[i]&1)return 0*printf("NO");
    return 0*printf("YES");
}