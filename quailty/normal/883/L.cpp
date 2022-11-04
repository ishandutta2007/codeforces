#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
struct Car
{
    int loc;
    ll lat;
    int id;
    bool operator < (const Car &t)const
    {
        return (loc==t.loc ? (lat==t.lat ? id<t.id : lat<t.lat) : loc<t.loc);
    }
};
set<Car> st;
priority_queue<pair<ll,Car> > busy;
int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1,x;i<=k;i++)
    {
        scanf("%d",&x);
        st.insert(Car{x,0,i});
    }
    ll now=0;
    for(int i=1;i<=m;i++)
    {
        ll t,w=0;
        int a,b;
        scanf("%lld%d%d",&t,&a,&b);
        while(!busy.empty() && -busy.top().first<=t)
            st.insert(busy.top().second),busy.pop();
        if(st.empty())
        {
            ll fr=busy.top().first;
            while(!busy.empty() && busy.top().first==fr)
                st.insert(busy.top().second),busy.pop();
            now=-fr;
        }
        if(t<now)w=now-t,t=now;
        auto itr=st.lower_bound(Car{a,0,0});
        int d[2]={n,n};
        Car ava[2];
        if(itr!=st.end())
        {
            ava[1]=*itr;
            d[1]=abs(ava[1].loc-a);
        }
        if(itr!=st.begin())
        {
            itr--;
            itr=st.lower_bound(Car{itr->loc,0,0});
            ava[0]=*itr;
            d[0]=abs(ava[0].loc-a);
        }
        int s=(vector<ll>{d[0],ava[0].lat,ava[0].id} > vector<ll>{d[1],ava[1].lat,ava[1].id});
        printf("%d %lld\n",ava[s].id,w+d[s]);
        st.erase(ava[s]);
        ll ed=t+d[s]+abs(b-a);
        busy.push({-ed,Car{b,ed,ava[s].id}});
    }
    return 0;
}