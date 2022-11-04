#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int d[2][2005];
int main()
{
    int n;
    scanf("%d",&n);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        res+=d[0][x+y];
        d[0][x+y]++;
        res+=d[1][x-y+1000];
        d[1][x-y+1000]++;
    }
    printf("%I64d",res);
    return 0;
}