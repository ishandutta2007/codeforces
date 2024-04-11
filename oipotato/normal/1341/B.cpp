#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,n)scanf("%d",&a[i]);
        int now=0;
        for(int i=2;i<k;i++)if(a[i]>a[i-1]&&a[i]>a[i+1])now++;
        int t=now+1,l=1;
        for(int i=2;i<=n-k+1;i++)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1])now--;
            if(a[i-1+k-1]>a[i-1+k-1-1]&&a[i-1+k-1]>a[i-1+k])now++;
            if(now+1>t)t=now+1,l=i;
        }
        printf("%d %d\n",t,l);
    }
    return 0;
}