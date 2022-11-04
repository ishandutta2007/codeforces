#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=100005;
const ll INF=(1LL<<40)-1;

ll max_health[MAXN],regen[MAXN];
vector<pair<ll,ll> > update[MAXN];

int main()
{
    ///input
    int n,m;
    scanf("%d%d",&n,&m);
    ll bounty,increase,damage;
    scanf("%lld%lld%lld",&bounty,&increase,&damage);
    for(int i=1;i<=n;i++)
    {
        ll start_health;
        scanf("%lld%lld%lld",&max_health[i],&start_health,&regen[i]);
        update[i].push_back({0,start_health});
    }
    for(int i=1;i<=m;i++)
    {
        ll time,enemy,health;
        scanf("%lld%lld%lld",&time,&enemy,&health);
        update[enemy].push_back({time,health});
    }
    for(int i=1;i<=n;i++)
        update[i].push_back({INF,0});
    for(int i=1;i<=n;i++)
        sort(update[i].begin(),update[i].end());
    ///get event
    vector<pair<ll,ll> > event;
    for(int i=1;i<=n;i++)
    {
        if(max_health[i]<=damage)
        {
            event.push_back({0,1});
            event.push_back({INF,-1});
            event.push_back({INF-1,0});
        }
        else
        {
            vector<pair<ll,ll> > tmp;
            for(int j=0;j+1<(int)update[i].size();j++)
            {
                ll st=update[i][j].first,ed=update[i][j+1].first-1;
                ll hp=update[i][j].second;
                if(hp>damage)continue;
                if(regen[i])ed=min(ed,st+(damage-hp)/regen[i]);
                tmp.push_back({st,ed});
            }
            for(int j=0,k=0;j<(int)tmp.size();j=k)
            {
                ll rig=tmp[j].first;
                while(k<(int)tmp.size() && tmp[k].first==rig)
                    rig=tmp[k++].second;
                event.push_back({tmp[j].first,1});
                event.push_back({rig+1,-1});
                event.push_back({rig,0});
            }
        }
    }
    ///scan line
    sort(event.begin(),event.end());
    ll res=0,cnt=0;
    for(int i=0;i<(int)event.size();i++)
    {
        cnt+=event[i].second;
        if(event[i].second>=0)
        {
            ll t=event[i].first;
            if(t==INF-1 && cnt && increase)return 0*printf("-1\n");
            res=max(res,cnt*(bounty+t*increase));
        }
    }
    printf("%lld\n",res);
    return 0;
}