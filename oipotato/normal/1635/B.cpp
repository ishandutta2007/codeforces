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
        int ans=0;
        for(int i=2;i<n;i++)if(a[i]>a[i-1]&&a[i]>a[i+1])ans++,a[i+1]=i+1==n?a[i]:max(a[i],a[i+2]);
        printf("%d\n",ans);
        rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}