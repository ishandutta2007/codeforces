#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e6+5;
int n,w;
vector<int> liczby[nax];
vector<pair<int,int> > events[nax];

const ll inf=-1e9-5;
int dd[nax];

vector<int> t;

void ini(int idx)
{
    int roz=1;
    int sz=liczby[idx].size();
    while(roz<sz) roz*=2;
    roz*=2;
    t.resize(roz);
    for(int i=roz/2;i<roz;i++) t[i]=inf;
    for(int i=1;i<sz;i++) t[i+roz/2]=liczby[idx][i];
    for(int i=roz/2-1;i>=1;i--) t[i]=max(t[i*2],t[i*2+1]);
}

int get(int lo,int hi,int u,int a,int b)
{
    if(lo==a && b==hi) return t[u];
    if(b<=a) return inf;
    int mid=(lo+hi)/2;
    int x1=get(lo,mid,u*2,a,min(b,mid));
    int x2=get(mid,hi,u*2+1,max(a,mid),b);
    return max(x1,x2);
}

void solve(int idx)
{
    int sz=liczby[idx].size();
    sz--;
    //cout<<sz<<" "<<t.size()<<endl;
    if(w>2*sz)
    {
        int naj=get(0,t.size()/2,1,1,sz+1);
        events[sz+1].push_back({idx,max(0,naj)});
    }
    for(int i=1;i<=sz;i++)
    {
        int akt=i;
        int naj=get(0,t.size()/2,1,max(0,akt-(w-sz)),min(akt+1,sz+1));
        if(w-sz>=akt)
        {
            naj=max(naj,0);
        }
        events[i].push_back({idx,naj});

    }
    for(int i=w-sz+1;i<=w;i++)
    {
        int akt=i;
        int naj=get(0,t.size()/2,1,max(0,akt-(w-sz)),min(akt+1,sz+1));
        if(akt>sz)
        {
            naj=max(naj,0);
        }
        events[i].push_back({idx,naj});
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        liczby[i].push_back(0);
        int l; cin>>l;
        while(l--)
        {
            int x; cin>>x; liczby[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++)
    {
        ini(i);
        solve(i);
    }
    ll sum=0;
    for(int i=1;i<=w;i++)
    {
        for(int j=0;j<events[i].size();j++)
        {
            pair<int,int> xdd=events[i][j];
            int ziomek=xdd.first;
            sum-=dd[ziomek];
            sum+=xdd.second;
            dd[ziomek]=xdd.second;
            //cout<<i<<" "<<xdd.first<<" "<<xdd.second<<endl;
        }
        cout<<sum<<" ";
    }

    return 0;
}