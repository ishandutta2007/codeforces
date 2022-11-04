#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll l[MAXN],r[MAXN],x[MAXN<<1];
ll cnt[MAXN<<1],res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&l[i],&r[i]),r[i]++;
        x[i*2-1]=l[i],x[i*2]=r[i];
    }
    sort(x+1,x+2*n+1);
    for(int i=1;i<=n;i++)
    {
        int tl=lower_bound(x+1,x+2*n+1,l[i])-x;
        int tr=lower_bound(x+1,x+2*n+1,r[i])-x;
        cnt[tl]++,cnt[tr]--;
    }
    for(int i=1;i<=2*n;i++)
        cnt[i]+=cnt[i-1];
    for(int i=1;i<=2*n;i++)
        res[cnt[i]]+=x[i+1]-x[i];
    for(int i=1;i<=n;i++)
        printf("%lld%c",res[i]," \n"[i==n]);
    return 0;
}