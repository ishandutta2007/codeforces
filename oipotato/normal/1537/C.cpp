#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010],ans[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int mn=a[2]-a[1];
        rep(i,n-1)mn=min(mn,a[i+1]-a[i]);
        int pos;
        rep(i,n-1)if(a[i+1]-a[i]==mn){pos=i;break;}
        ans[1]=a[pos];ans[n]=a[pos+1];
        int now=2;
        for(int i=pos+2;i<=n;i++)ans[now++]=a[i];
        rep(i,pos-1)ans[now++]=a[i];
        rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}