#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int k;
struct query
{
    int l;
    int r;
    int nr;
};

bool por(query a,query b)
{
    if(a.l/k==b.l/k)
    {
        if((a.l/k%2)==false) return a.r<b.r;
        return a.r>b.r;
    }

    return a.l<b.l;
}

const int N=2e5+5;
vector<int> a(N,0);
long long int res[N];
int ile[1111111];
long long int ans=0;
void dodaj(int i)
{
        int t=a[i];
        ile[t]++;
        int x=ile[t];
        ans+=t*(2*x-1);
}

void usun(int i)
{
    int t=a[i];
    ile[t]--;
    int x=ile[t];
    ans-=t*(2*x+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ile,0,sizeof ile);
    int n,t; cin>>n>>t;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<query> tab;
    for(int i=0;i<t;i++)
    {
        int l,r; cin>>l>>r;
        l--; r--;
        query xd;
        xd.l=l;
        xd.r=r;
        xd.nr=i+1;
        tab.push_back(xd);
    }
    k=ceil(sqrt(n));
    sort(tab.begin(),tab.end(),por);
    int l=tab[0].l;
    int r=tab[0].r;
    for(int i=l;i<=r;i++)
    {
        dodaj(i);
    }
    res[tab[0].nr]=ans;
    for(int i=1;i<tab.size();i++)
    {
        while(tab[i].l<l)
        {
            l--;
            dodaj(l);
        }
        while(tab[i].r>r)
        {
            r++;
            dodaj(r);
        }
        while(tab[i].l>l)
        {
            usun(l);
            l++;
        }
        while(tab[i].r<r)
        {
            usun(r);
            r--;
        }
        res[tab[i].nr]=ans;
    }
    for(int i=1;i<=t;i++) cout<<res[i]<<"\n";
    return 0;
}