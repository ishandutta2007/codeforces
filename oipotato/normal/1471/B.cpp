#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[100010],b[100010],n;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,x;
        LL ans=0;scanf("%d%d",&n,&x);
        rep(i,n)
        {
            scanf("%d",&a[i]);ans+=a[i];
            b[i]=0;
            for(int j=a[i];j%x==0;j/=x,b[i]++);
        }
        int mn=b[1];
        rep(i,n)mn=min(mn,b[i]);
        int pos=1;
        rep(i,n)if(b[i]==mn){pos=i;break;}
        rep(i,n)ans+=(LL)(mn+1-(i>=pos))*a[i];
        printf("%lld\n",ans);
    }
    return 0;
}