#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=(1<<21)+5;

int done[nax];
int ile[nax];
int val[nax];
int a[nax];
int pot[nax];
int n;
vector<bool> odw(nax,false);
vector<int> xd;

void ini()
{
    int j=0;
    for(int i=1;i<nax;i*=2)
    {
        val[i]=j; j++;
    }
    j=1;
    for(int i=0;i<=21;i++)
    {
        pot[i]=j;
        j*=2;
    }
}

void ss(int x,int idx)
{
    if(odw[x]==true) return;
    if(x==0)
    {
        if(ile[x]<2)
        {
            ile[x]++;
            done[0]=idx;
            odw[x]=true;
            xd.push_back(x);
            return;
        }
        else return;
    }
    if(ile[x]==2)
    {
        return;
    }
    ile[x]++;
    done[x]=idx;
    odw[x]=true;
    xd.push_back(x);
    int rest=0;
    while(x)
    {
        int wartosc=(x&(~(x-1)));
        x-=wartosc;
        ss(x|rest,idx);
        rest+=wartosc;
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ini();
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        ss(a[i],i);
        for(int j=0;j<xd.size();j++)
        {
            odw[xd[j]]=false;
        }
        xd.clear();
    }
    int res=0;
    for(int i=1;i<=n-2;i++)
    {
        int akt=a[i];
        vector<int> bity;
        for(int j=20;j>=0;j--)
        {
            if(akt&pot[j]);
            else bity.push_back(j);
        }
        int kappa=0;
        for(int j=0;j<bity.size();j++)
        {
            int t=kappa;
            t|=(pot[bity[j]]);
            if(ile[t]==2 && done[t]>i) kappa=t;
        }
        res=max(res,kappa|akt);
    }
    cout<<res;
    return 0;
}