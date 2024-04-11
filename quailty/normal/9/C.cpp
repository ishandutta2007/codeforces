#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int p[3005];
int main()
{
    int tot=0;
    for(int i=1;i<=10;i++)
        for(int j=0;j<(1<<i);j++)
        {
            int t=0;
            for(int k=0;k<i;k++)
                t=10*t+(j>>k&1);
            p[tot++]=t;
        }
    sort(p,p+tot);
    tot=unique(p,p+tot)-p;
    int n;
    scanf("%d",&n);
    printf("%d\n",upper_bound(p,p+tot,n)-p-1);
    return 0;
}