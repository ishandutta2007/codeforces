#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int cnt=0,a[1<<11];
    rep(len,9)
    rep(i,(1<<len))
    {
        int x=0;
        rep(j,len)if(((i-1)>>(j-1))&1)x=x*10+7;else x=x*10+4;
        a[++cnt]=x;
    }
    sort(a+1,a+cnt+1);
    int n;scanf("%d",&n);
    printf("%d\n",lower_bound(a+1,a+cnt+1,n)-a);
    return 0;
}