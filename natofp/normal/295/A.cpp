#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct op
{
    int l;
    int r;
    int d;
};

int main()
{
    int n,m,k; cin>>n>>m>>k;
    long long int * a=new long long int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<op> xd;
    for(int i=0;i<m;i++)
    {
        int x,y,z; cin>>x>>y>>z;
        op nowy;
        nowy.l=x;
        nowy.r=y;
        nowy.d=z;
        xd.push_back(nowy);
    }
    vector<long long int> DA(m+1,0);
    for(int i=0;i<k;i++)
    {
        int x,y; cin>>x>>y;
        x--; y--;
        DA[x]++;
        DA[y+1]--;
    }
    for(int i=1;i<=m;i++)
    {
        DA[i]+=DA[i-1];
    }
     vector<long long int> DA2(n+1,0);
     for(int i=0;i<m;i++)
     {
         int x,y,z;
         x=xd[i].l;
         y=xd[i].r;
         z=xd[i].d;
         long long ile=DA[i];
         x--; y--;
         DA2[x]+=z*ile;
         DA2[y+1]-=z*ile;
     }
     for(int i=1;i<=n;i++)
    {
        DA2[i]+=DA2[i-1];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]+DA2[i]<<" ";
    }
    return 0;
}