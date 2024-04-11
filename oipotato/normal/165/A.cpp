#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,x[210],y[210];
    scanf("%d",&n);
    rep(i,n)scanf("%d%d",&x[i],&y[i]);
    int ans=0;
    rep(i,n)
    {
        int flag=0;
        rep(j,n)
        {
            if(x[j]>x[i]&&y[j]==y[i])flag|=1;
            if(x[j]<x[i]&&y[j]==y[i])flag|=2;
            if(x[j]==x[i]&&y[j]<y[i])flag|=4;
            if(x[j]==x[i]&&y[j]>y[i])flag|=8;
        }
        if(flag==15)ans++;
    }
    printf("%d\n",ans);
    return 0;
}