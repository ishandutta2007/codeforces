#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        int a[200010];rep(i,n+2)scanf("%d",&a[i]);
        sort(a+1,a+n+3);
        LL sum=0;
        rep(i,n)sum+=a[i];
        if(sum==a[n+1]||sum==a[n+2])
        {
            rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
            continue;
        }
        sum+=a[n+1];
        int pos=-1;
        rep(i,n)if(sum-a[i]==a[n+2]){pos=i;break;}
        if(pos==-1)puts("-1");
        else
        {
            swap(a[pos],a[n+1]);
            rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}