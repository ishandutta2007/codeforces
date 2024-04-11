#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[55],ans[55],c[1010],n;
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]);
    int cnt=0;
    for(int i=n;i;i--)if(!c[a[i]])ans[++cnt]=a[i],c[a[i]]=1;
    reverse(ans+1,ans+cnt+1);
    printf("%d\n",cnt);
    rep(i,cnt)printf("%d%c",ans[i]," \n"[i==cnt]);
    return 0;
}