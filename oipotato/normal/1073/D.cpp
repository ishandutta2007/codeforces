#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
long long T,ans;
int n,a[200010];
int main()
{
    scanf("%d%lld",&n,&T);
    rep(i,n)scanf("%d",&a[i]);
    for(;;)
    {
        long long sum=0;
        int cnt=0;
        rep(i,n)if(a[i]<=T)sum+=a[i],cnt++;
        if(!sum)break;
        if(T>=2*sum)
        {
            long long tmp=(T-2*sum)/sum;
            ans+=tmp*cnt;
            T-=tmp*sum;
            for(;T-sum>=sum;T-=sum,ans+=cnt);
        }
        rep(i,n)if(a[i]<=T)T-=a[i],ans++;
    }
    printf("%lld\n",ans);
	return 0;
}