#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int a[10],sum=0;
    rep(i,4)scanf("%d",&a[i]),sum+=a[i];
    if(sum&1){puts("NO");return 0;}
    for(int i=0;i<(1<<4);i++)
    {
        int now=0;
        rep(j,4)if((i>>(j-1))&1)now+=a[j];
        if(now==sum/2){puts("YES");return 0;}
    }
    puts("NO");
    return 0;
}