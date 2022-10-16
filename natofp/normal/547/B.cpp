#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
int a[nax];
int n;
int par[nax];
int roz[nax];
int maxx=0;
int akt=1e9;
void create(int k)
{
    par[k]=k;
    roz[k]=1;
    maxx=max(maxx,1);
}

int find(int v)
{
    if(par[v]==v) return v;
    return par[v]=find(par[v]);
}

void unionn(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(roz[a]<roz[b]) swap(a,b);
    roz[a]+=roz[b];
    roz[b]=0;
    par[b]=a;
    maxx=max(maxx,roz[a]);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) par[i]=-1;
    vector<pair<int,int> > b;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b.push_back({a[i],i});
    }
    sort(b.begin(),b.end());
    vector<int> ans(n+1,0);
    int wsk=n-1;
    for(int i=1;i<=n;i++)
    {
        while(maxx<i)
        {
            create(b[wsk].second);
            wsk--;
            akt=b[wsk+1].first;
            int ziomek=b[wsk+1].second;
            if(ziomek-1>=1 && par[ziomek-1]!=-1) unionn(ziomek,ziomek-1);
            if(ziomek+1<=n && par[ziomek+1]!=-1) unionn(ziomek,ziomek+1);
        }
        ans[i]=akt;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}