#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<pair<ll,int> >Event;
int main()
{
    int h,q;
    scanf("%d%d",&h,&q);
    for(int i=1;i<=q;i++)
    {
        int x,res;
        ll L,R;
        scanf("%d%I64d%I64d%d",&x,&L,&R,&res);
        for(int j=x+1;j<=h;j++)
        {
            L=(L<<1);
            R=(R<<1|1);
        }
        if(res==1)
        {
            Event.push_back(make_pair(L,-1));
            Event.push_back(make_pair(R,1));
        }
        else
        {
            if(L>(1LL<<(h-1)))
            {
                Event.push_back(make_pair(1LL<<(h-1),-1));
                Event.push_back(make_pair(L-1,1));
            }
            if(R<(1LL<<h)-1);
            {
                Event.push_back(make_pair(R+1,-1));
                Event.push_back(make_pair((1LL<<h)-1,1));
            }
        }
    }
    Event.push_back(make_pair(1LL<<(h-1),-1));
    Event.push_back(make_pair((1LL<<h)-1,1));
    sort(Event.begin(),Event.end());
    int cnt=0;
    ll tot=0,la=1LL<<(h-1),loc=0;
    for(int i=0;i<Event.size();i++)
    {
        if(cnt==q+1)tot+=Event[i].first-la+1;
        cnt-=Event[i].second;
        if(cnt==q+1)la=Event[i].first;
    }
    if(tot>1)printf("Data not sufficient!");
    else if(tot==0)printf("Game cheated!");
    else printf("%I64d",la);
    return 0;
}