#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    int l=1,r=2*k;
    while(l<r)
    {
        int m=(l+r)/2;
        vector<int> cnt(n+1,m);
        int rem=0;
        for(int i=1;i<=k;i++)
            if(cnt[a[i]])cnt[a[i]]--,rem++;
        for(int i=1;i<=n && rem<k;i++)
            rem+=cnt[i]/2;
        if(rem>=k)r=m;
        else l=m+1;
    }
    return 0*printf("%d\n",l);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}