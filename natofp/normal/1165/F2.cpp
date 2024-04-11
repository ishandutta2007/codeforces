#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,m;
const int nax=2e5+5;
int ile[nax];
vector<int> offers[nax];
vector<int> dni[nax*2];

bool czy(int x)
{
    for(int i=0;i<2*nax;i++) dni[i].clear();
    vector<int> oferty(nax,-1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<offers[i].size();j++)
        {
            int dzien=offers[i][j];
            if((dzien<=x && dzien>oferty[i]))
            {
                oferty[i]=dzien;
            }
        }
    }
    int potrzeba[nax];
    for(int i=1;i<=n;i++) potrzeba[i]=ile[i];
    for(int i=1;i<=n;i++)
    {
        if(oferty[i]!=-1)
        {
            dni[oferty[i]].push_back(i);
        }
    }
    int stan=0;
    for(int i=1;i<=x;i++)
    {
        stan++;
        for(int j=0;j<dni[i].size();j++)
        {
            int t=dni[i][j];
            if(potrzeba[t]>0)
            {
                int iletrzeba=potrzeba[t];
                int ilemozna=stan;
                potrzeba[t]-=min(iletrzeba,ilemozna);
                stan-=min(iletrzeba,ilemozna);
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=potrzeba[i];
    }
    if(sum*2<=stan) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>ile[i];
    for(int i=1;i<=m;i++)
    {
        int d,t; cin>>d>>t;
        offers[t].push_back(d);
    }
    int lo=1;
    int hi=2*nax-1;
    while(lo+1<hi)
    {
        int mid=(lo+hi)/2;
        if(czy(mid)) hi=mid;
        else lo=mid;
    }
    if(czy(lo)) cout<<lo;
    else cout<<hi;

    return 0;
}