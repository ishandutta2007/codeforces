#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,s;
    scanf("%i %i",&n,&s);
    ll times[n];
    set<pair<pair<ll,int>,pair<int,int> > > events;
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        events.insert({{a,1},{b,i}});
    }
    bool busy=false;
    for(set<pair<pair<ll,int>,pair<int,int> > >::iterator it=events.begin();it!=events.end();it++)
    {
        pair<pair<ll,int>,pair<int,int> > tr=*it;
        ll t=tr.first.first,tip=tr.first.second,d=tr.second.first,id=tr.second.second;
        //printf("Usao za %i %i %i %i\n",t,tip,d,id);
        if(tip==1)
        {
            if(q.size()<s)
            {
                if(q.size()==0&&!busy)
                {
                    times[id]=t+d;
                    events.insert({{(ll)t+d,0},{0,id}});
                    busy=true;
                }
                else
                {
                    //printf("Dodajem %i %i u q\n",d,id);
                    q.push({d,id});
                }
            }
            else
            {
                times[id]=-1;
            }
        }
        if(tip==0)
        {
            if(q.size()>0)
            {
                pair<int,int> lol=q.front();
                q.pop();
                times[lol.second]=(ll)t+lol.first;
                events.insert({{(ll)t+lol.first,0},{0,lol.second}});
            }
            else
            {
                busy=false;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%lld ",times[i]);
    }
    return 0;
}