#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> a;
const int N=1e6+5;
int ile[N];
int p[N];

int ilosc(int l,int r)
{
    return p[r]-p[l-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(p,0,sizeof p);
    memset(ile,0,sizeof ile);
    cin>>n>>k;
    int naj=1e6;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        naj=min(naj,x);
        ile[x]++;
        a.push_back(x);
    }
    p[0]=0;
    for(int i=1;i<=1e6;i++)
    {
        p[i]=p[i-1]+ile[i];
    }
    if(naj<=k+1) {cout<<naj<<endl; return 0;}
    int ans=k+1;
    for(int d=k+1;d<=naj;d++)
    {
        int res=0;
        for(int i=1;i*d<=1e6;i++)
        {
            res+=ilosc(i*d,min(i*d+k,1000000));
        }
        if(res==n) ans=d;
    }
    cout<<ans;

    return 0;
}