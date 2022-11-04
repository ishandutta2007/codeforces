#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1000000000000000000LL;
ll p[25];
vector<ll> lef,rig;
void dfs1(int dep,int mx,ll now)
{
    if(dep>mx)
    {
        lef.push_back(now);
        return;
    }
    while(1)
    {
        dfs1(dep+1,mx,now);
        if(now>INF/p[dep])break;
        now*=p[dep];
    }
}
void dfs2(int dep,int mx,ll now)
{
    if(dep>mx)
    {
        rig.push_back(now);
        return;
    }
    while(1)
    {
        dfs2(dep+1,mx,now);
        if(now>INF/p[dep])break;
        now*=p[dep];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i]);
    sort(p+1,p+n+1);
    dfs1(1,min(n,6),1);
    sort(lef.begin(),lef.end());
    dfs2(min(n,6)+1,n,1);
    sort(rig.begin(),rig.end());
    ll k;
    scanf("%lld",&k);
    ll tl=1,tr=INF;
    while(tl<tr)
    {
        ll tm=(tl+tr)/2,cnt=0;
        for(int i=(int)lef.size()-1,j=0;i>=0;i--)
        {
            while(j<(int)rig.size() && lef[i]<=tm/rig[j])j++;
            cnt+=j;
        }
//        for(int i=0;i<(int)lef.size();i++)
//            cnt+=upper_bound(rig.begin(),rig.end(),tm/lef[i])-rig.begin();
        if(cnt>=k)tr=tm;
        else tl=tm+1;
    }
    printf("%lld\n",tl);
    return 0;
}