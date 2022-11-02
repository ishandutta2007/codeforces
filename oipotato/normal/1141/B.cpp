#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[400010],n;
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]),a[i+n]=a[i];
    int now=0,ans=0;
    rep(i,n*2)if(a[i])now++,ans=max(ans,now);else now=0;
    printf("%d\n",ans);
    return 0;
}