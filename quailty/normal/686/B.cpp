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
        for(int j=1;j<n;j++)
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                printf("%d %d\n",j,j+1);
            }
    return 0;
}