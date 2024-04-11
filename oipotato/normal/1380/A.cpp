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
        int a[1010],x[1010],y[1010],n;
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]),x[i]=y[i]=0;
        rep(i,n)rep(j,i-1)if(a[i]<a[j])y[j]=i;else x[i]=j;
        bool flag=0;
        rep(i,n)if(x[i]&&y[i]){printf("YES\n%d %d %d\n",x[i],i,y[i]);flag=1;break;}
        if(!flag)puts("NO");
    }
    return 0;
}