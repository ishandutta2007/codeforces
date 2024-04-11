#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,sum,a[33],b[33];
    scanf("%d%d",&n,&sum);
    int l=0,r=0;
    rep(i,n)scanf("%d%d",&a[i],&b[i]),l+=a[i],r+=b[i];
    if(sum<l||sum>r)puts("NO");
    else
    {
        puts("YES");
        sum-=l;
        rep(i,n)
        {
            int tmp=min(b[i]-a[i],sum);
            sum-=tmp;
            printf("%d%c",a[i]+tmp," \n"[i==n]);
        }
    }
    return 0;
}