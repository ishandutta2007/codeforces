#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=3e6;

int czy[nax];
int ile[nax];
vector<int> primes(300000,0);

void pre()
{
    for(int i=0;i<nax;i++)
    {
        czy[i]=i;
        ile[i]=0;
    }
    for(int i=2;i<nax;i++)
    {
        if(czy[i]!=i) continue;
        for(int j=2*i;j<nax;j+=i)
        {
            czy[j]=min(czy[j],i);
        }
    }
    int wsk=1;
    for(int i=2;i<nax;i++)
    {
        if(czy[i]==i)
        {
            primes[wsk++]=i;
        }
    }
}

int main()
{
    pre();
    int n; cin>>n;
    for(int i=0;i<2*n;i++)
    {
        int x; cin>>x;
        ile[x]++;
    }
    vector<int> a;
    for(int i=nax-1;i>=2;i--)
    {
        if(ile[i]==0) continue;
        if(czy[i]==i) continue;
        for(int j=0;j<ile[i];j++)
        {
            a.push_back(i);
        }
        ile[i/czy[i]]-=ile[i];
        ile[i]=0;
    }
    for(int i=0;i<=200000;i++)
    {
        for(int j=0;j<ile[i];j++)
        {
            a.push_back(i);
        }
        ile[primes[i]]-=ile[i];
        ile[i]=0;
    }
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
    return 0;
}