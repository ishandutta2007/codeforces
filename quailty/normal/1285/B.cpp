#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
ll a[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        ll sum=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]),sum+=a[i];
        ll res=-INF,now=0;
        for(int i=1;i<n;i++)
            now=max(now,0LL)+a[i],res=max(res,now);
        now=0;
        for(int i=n;i>1;i--)
            now=max(now,0LL)+a[i],res=max(res,now);
        printf("%s\n",(sum>res ? "YES" : "NO"));
    }
    return 0;
}