#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define x first.first
#define type first.second
#define y second.first
#define koliko second.second.first
#define index second.second.second

using namespace std;

int main()
{
    int n,m;
    scanf("%i",&n);
    vector<pair<pair<int,int>,pair<int,pair<int,int> > > > events;
    vector<int> res(n+1);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        events.pb({{a,1},{b,{-1,i+1}}});
    }
    scanf("%i",&m);
    for(int i=0;i<m;i++)
    {
        int a,b,k;
        scanf("%i %i %i",&a,&b,&k);
        events.pb({{a,0},{b,{k,i+1}}});
    }
    sort(events.begin(),events.end());
    set<pair<int,pair<int,int> > > skup;
    pair<int,pair<int,int> > maxx=make_pair(INT_MAX,make_pair(0,0)),tr;
    skup.insert(maxx);
    for(int i=0;i<events.size();i++)
    {
        //printf("Usao za %i %i %i\n",events[i].x,events[i].y,events[i].koliko);
        if(events[i].type==1)
        {
            tr=*skup.lower_bound({events[i].y,{0,0}});
            if(tr.first==INT_MAX)
            {
                printf("NO\n");
                return 0;
            }
            skup.erase(tr);
            tr.second.first--;
            if(tr.second.first!=0)
            {
                skup.insert(tr);
            }
            res[events[i].index]=tr.second.second;
        }
        else
        {
            //printf("Dodajem %i %i %i\n",events[i].y,events[i].koliko,events[i].index);
            skup.insert({events[i].y,{events[i].koliko,events[i].index}});
        }
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        printf("%i ",res[i+1]);
    }
    return 0;
}