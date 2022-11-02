#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
LL cal(int l,int r){return (LL)(l+r)*(r-l+1)/2;}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int ans[110][110],n;scanf("%d",&n);
        if(n&1)
        {
            rep(i,n)rep(j,n)ans[i][j]=1;
            rep(i,n)ans[i][i]=113-(n-2)-4;
            rep(i,n)ans[i][i%n+1]=4;
        }
        else
        {
            rep(i,n)rep(j,n)ans[i][j]=1;
            rep(i,n)ans[i][i]=113-(n-1);
        }
        rep(i,n)rep(j,n)printf("%d%c",ans[i][j]," \n"[j==n]);
    }
    return 0;
}