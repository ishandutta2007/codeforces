#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int cnt[1<<17];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        res+=cnt[a^x];
        cnt[a]++;
    }
    printf("%I64d",res);
    return 0;
}