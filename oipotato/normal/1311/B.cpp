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
        int n,m,a[110],c[110];
        scanf("%d%d",&n,&m);
        rep(i,n)scanf("%d",&a[i]),c[i]=0;
        rep(i,m){int x;scanf("%d",&x);c[x]=1;}
        rep(i,n)
        if(c[i])
        {
            int j=i;
            for(;c[j];j++);
            sort(a+i,a+j+1);
            i=j;
        }
        bool flag=1;
        rep(i,n-1)if(a[i]>a[i+1])flag=0;
        puts(flag?"YES":"NO");
    }
    return 0;
}