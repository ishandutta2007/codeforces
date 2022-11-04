#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int x[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int m;
        scanf("%d",&m);
        printf("%d\n",upper_bound(x+1,x+n+1,m)-x-1);
    }
    return 0;
}