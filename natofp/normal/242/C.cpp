#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5;
ll const BASE=1e9+1;

int main()
{
    ll start,stop;
    ll b,c,d,e; cin>>b>>c>>d>>e;
    start=BASE*b+c;
    stop=BASE*d+e;
    int n; cin>>n;
    ll * a=new ll[n];
    map<ll,bool> xd;
    for(int i=0;i<n;i++)
    {
        ll r,x,y; cin>>r>>x>>y;
        for(int j=x;j<=y;j++)
        {
            ll t=r*BASE+j;
            xd[t]=true;
        }
    }
    xd[start]=true;
    xd[stop]=true;
    queue<pair<ll,int> > q;
    q.push({start,0});
    while(q.empty()==false)
    {
        pair<ll,int> t=q.front();
        q.pop();
        ll ile=t.first;
        int dg=t.second;
        if(ile==stop) {cout<<dg; return 0;}
        if(xd[ile]==false) continue;
        xd[ile]=false;
        if(ile%BASE!=1) q.push({ile-1,dg+1});
        if(ile%BASE!=BASE-1) q.push({ile+1,dg+1});
        if(ile/BASE!=1) q.push({ile-BASE,dg+1});
        if(ile/BASE!=BASE-1) q.push({ile+BASE,dg+1});
        if(ile%BASE!=1 && ile/BASE!=1) q.push({ile-BASE-1,dg+1});
        if(ile%BASE!=1 && ile/BASE!=BASE-1) q.push({ile+BASE-1,dg+1});
        if(ile%BASE!=BASE-1 && ile/BASE!=1) q.push({ile-BASE+1,dg+1});
        if(ile%BASE!=BASE-1 && ile/BASE!=BASE-1) q.push({ile+BASE+1,dg+1});
    }
    cout<<-1;
    return 0;
}