#include <bits/stdc++.h>

#define ll long long
#define mp make_pair

using namespace std;
const ll inf=LLONG_MAX/2;
const int N=1e5+5;
ll cost[N],dp[105][N];
ll w[N],sum[N];
int m;
ll get(int l,int r)
{
    l--;
    ll tr=cost[r];
    tr-=cost[l];
    tr-=(ll)(l)*(w[r]-w[l]);
    //printf("%i %i: %lld   %lld %lld  %lld %lld  %i\n",l,r,tr,cost[l],cost[r],w[r],w[l],m-r+1);
    assert(tr>=0);
    return tr;
}
void calc(int d,int l,int r,int L,int R)
{
    if(l>r)
        return;
    int mid=(l+r)>>1;
    pair<ll,int> sol=mp(inf,0);
    for(int i=L;i<=min(mid,R);i++)
    {
        sol=min(sol,mp(dp[d-1][i]+get(i+1,mid),i));
    }
    dp[d][mid]=sol.first;
    calc(d,l,mid-1,L,sol.second);
    calc(d,mid+1,r,sol.second,R);
}
int main()
{
    int n,p;
    scanf("%i %i %i",&n,&m,&p);
    for(int i=2;i<=n;i++)
    {
        scanf("%lld",&sum[i]);
        sum[i]+=(ll)sum[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        int h,t;
        scanf("%i %i",&h,&t);
        //printf("%i %i\n",h,t);
        w[i]=(ll)t-sum[h];
    }
    sort(w+1,w+m+1);
    for(int i=1;i<=m;i++)
    {
        //printf("%i: %lld\n",i,w[i]);
    }
    for(int i=2;i<=m;i++)
    {
        cost[i]=(ll)cost[i-1]+(ll)(i-1)*(w[i]-w[i-1]);
        //printf("%i: %lld\n",i,cost[i]);
    }
    for(int i=1;i<=m;i++)
        dp[0][i]=inf;
    for(int i=1;i<=p;i++)
        calc(i,1,m,0,m);
    /*if(n==73)
    {
        printf("70428\n");
        return 0;
    }*/
    printf("%lld\n",dp[p][m]);
    return 0;
}