#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int ans,c[110][110];
int main()
{
    int n;scanf("%d",&n);
    rep(i,n)
    {
        int h,m;scanf("%d%d",&h,&m);
        c[h][m]++;
        ans=max(ans,c[h][m]);
    }
    printf("%d\n",ans);
    return 0;
}