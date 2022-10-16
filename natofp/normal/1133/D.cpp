#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ulamek
{
    long long int a,b;
};

bool por(ulamek x,ulamek y)
{
    return (long long int)x.a*y.b<x.b*y.a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int xxx=0;
    int n; cin>>n;
    vector<ulamek> xx;
    vector<long long int> g;
    vector<long long int> h;
    for(int i=0;i<n;i++)
    {
        long long int s; cin>>s; g.push_back(s);
    }
    for(int i=0;i<n;i++)
    {
        long long int s; cin>>s; h.push_back(s);
    }
    for(int i=0;i<n;i++)
    {
        long long int x,y; y=g[i]; x=h[i];
        if(y==0)
        {
            if(x==0) xxx++;
            continue;
        }
        ulamek nowy;
        x*=-1;
        if(x<0 && y<0) {x*=-1; y*=-1;}
        else if(x<0 || y<0)
        {
            if(y<0)
            {
                x*=-1;
                y*=-1;
            }
        }
        nowy.a=x;
        nowy.b=y;
        xx.push_back(nowy);
    }
    sort(xx.begin(),xx.end(),por);
    int akt,ans;
    if(xx.size()>0)
    {
        akt=1; ans=1;
    }
    else
    {
        akt=0;
        ans=0;
    }
    for(int i=1;i<xx.size();i++)
    {
        if((long long int)xx[i].a*xx[i-1].b==xx[i].b*xx[i-1].a) {akt++;}
        else
        {
            ans=max(ans,akt);
            akt=1;
        }
    }
    ans=max(ans,akt);
    cout<<ans+xxx;
    return 0;
}