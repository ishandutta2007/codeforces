#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,a[200010];
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        int now=n,ans=0;
        for(;now>1;)
        {
            for(;now>1&&a[now-1]==a[n];now--);
            if(now==1)break;
            now=max(1,now-(n-now+1));ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}