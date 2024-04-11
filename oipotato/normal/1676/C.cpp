#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[55][10];
int n,m;
int cal(int x,int y)
{
    int res=0;
    rep(i,m)res+=abs(s[x][i]-s[y][i]);
    return res;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&n,&m);
        rep(i,n)scanf("%s",s[i]+1);
        int ans=cal(1,2);
        rep(i,n)rep(j,i-1)ans=min(ans,cal(i,j));
        printf("%d\n",ans);
    }
    return 0;
}