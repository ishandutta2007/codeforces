#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=105;
ll a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1,[](ll x,ll y)
         {
            int cnt[2]={0,0};
            ll tx=x,ty=y;
            while(tx%3==0)tx/=3,cnt[0]++;
            while(ty%3==0)ty/=3,cnt[1]++;
            return cnt[0]==cnt[1] ? x<y : cnt[0]>cnt[1];
         });
    for(int i=1;i<=n;i++)
        printf("%lld%c",a[i]," \n"[i==n]);
    return 0;
}