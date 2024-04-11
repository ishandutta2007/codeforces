#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int N=400002;
vector<pair<int,int> > sve1[N];
vector<vector<pair<int,int> > > sve;
vector<int> xx;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first>b.first)
        return true;
    if(a.first<b.first)
        return false;
    if(a.second<b.second)
        return true;
    return false;
}
ll ud(int x,int k,int y,int l)
{
    int x1,y1,x2,y2;
    if(k==0)
    {
        x1=xx[sve[x][0].first];
        y1=xx[sve[x][0].second];
    }
    else
    {
        x1=xx[sve[x].back().first];
        y1=xx[sve[x].back().second];
    }
    if(l==0)
    {
        x2=xx[sve[y][0].first];
        y2=xx[sve[y][0].second];
    }
    else
    {
        x2=xx[sve[y].back().first];
        y2=xx[sve[y].back().second];
    }
    //printf("%i %i   %i %i\n",x1,y1,x2,y2);
    assert(abs(x2-x1)<=1e9&&abs(y1-y2)<=1e9);
    return abs(x2-x1)+abs(y1-y2);
}
int main()
{
    int n;
    scanf("%i",&n);
    int x1[n];
    int y1[n];
    map<int,int> mapa;
    for(int i=0;i<n;i++)
    {
        scanf("%i %i",&x1[i],&y1[i]);
        xx.pb(x1[i]);
        xx.pb(y1[i]);
    }
    sort(xx.begin(),xx.end());
    xx.erase(unique(xx.begin(),xx.end()),xx.end());
    for(int i=0;i<xx.size();i++)
    {
        mapa[xx[i]]=i;
    }
    int nivo=xx.size();
    for(int i=0;i<n;i++)
    {
        int x=mapa[x1[i]];
        int y=mapa[y1[i]];
        int m=max(x,y);
        //printf("%i %i %i   %i %i\n",x,y,m,x1[i],y1[i]);
        sve1[m].pb({x,y});
    }
    for(int i=0;i<nivo;i++)
    {
        if(sve1[i].size()>0)
        {
            sve.pb(sve1[i]);
        }
    }
    nivo=sve.size();
    for(int i=0;i<nivo;i++)
    {
        sort(sve[i].begin(),sve[i].end(),cmp);
    }
    vector<int> udaljenost(nivo);
    for(int i=0;i<nivo;i++)
    {
        udaljenost[i]=ud(i,0,i,1);
        //printf("Udaljenost od %i: %i\n",i,udaljenost[i]);
    }
    ll dp[nivo][2];
    dp[nivo-1][0]=dp[nivo-1][1]=udaljenost[nivo-1];
    for(int i=nivo-2;i>=0;i--)
    {
        dp[i][0]=(ll)min((ll)udaljenost[i]+ud(i,1,i+1,0)+dp[i+1][0],(ll)udaljenost[i]+ud(i,1,i+1,1)+dp[i+1][1]);
        dp[i][1]=(ll)min((ll)udaljenost[i]+ud(i,0,i+1,0)+dp[i+1][0],(ll)udaljenost[i]+ud(i,0,i+1,1)+dp[i+1][1]);
    }
    int x11=xx[sve[0][0].first];
    int y11=xx[sve[0][0].second];
    int x22=xx[sve[0].back().first];
    int y22=xx[sve[0].back().second];
    ll res=min(dp[0][0]+x11+y11,dp[0][1]+x22+y22);
    printf("%lld\n",res);
    return 0;
}