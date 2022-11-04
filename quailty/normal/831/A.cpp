#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            bool isok=1;
            for(int k=i;k<j;k++)
                isok&=(a[k]==a[k+1]);
            for(int k=1;k<i;k++)
                isok&=(a[k]<a[k+1]);
            for(int k=j;k<n;k++)
                isok&=(a[k]>a[k+1]);
            if(isok)return 0*printf("YES");
        }
    return 0*printf("NO");
}