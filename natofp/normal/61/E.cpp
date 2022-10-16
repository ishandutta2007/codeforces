#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<int> s;

const int roz=(1<<21);

int get(int x)
{
    int lo=0;
    int hi=n-1;
    while(lo+1<hi)
    {
        int mid=(lo+hi)/2;
        if(s[mid]<=x) lo=mid;
        else hi=mid;
    }
    while(s[lo]!=x) lo++;
    return lo;
}

void obrob()
{
    s=a;
    sort(s.begin(),s.end());
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int t=a[i];
        int pos=get(a[i]);
        res.push_back(pos+1);
    }
    a=res;
}

int licz[roz];

void drzewoliczdodaj(int pos,int v)
{
    pos+=roz/2;
    while(pos>=1)
    {
        licz[pos]+=v;
        pos/=2;
    }
}

int getsumalicz(int lo,int hi,int u,int a,int b)
{
    if(a==lo && b==hi)
    {
        return licz[u];
    }
    if(b<=a) return 0;
    int mid=(lo+hi)/2;
    int x,y;
    x=getsumalicz(lo,mid,u*2,a,min(b,mid));
    y=getsumalicz(mid,hi,u*2+1,max(a,mid),b);
    return x+y;
}

long long int tree[roz];

void update(int lo,int hi,int u,int a,int b,int c)
{
    if(a==lo && b==hi)
    {
        tree[u]+=c;
        return;
    }
    if(b<=a) return;
    int mid=(lo+hi)/2;
    update(lo,mid,u*2,a,min(b,mid),c);
    update(mid,hi,u*2+1,max(a,mid),b,c);
}

long long int suma(int v)
{
    long long int ans=0;
    v+=roz/2;
    while(v>=1)
    {
        ans+=tree[v];
        v/=2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(tree,0,sizeof tree);
    memset(licz,0,sizeof licz);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    obrob();
    long long int ans=0;
    drzewoliczdodaj(a[0],1);
    for(int i=1;i<n;i++)
    {
        drzewoliczdodaj(a[i],1);
        int t=getsumalicz(0,roz/2,1,a[i]+1,n+1);
        update(0,roz/2,1,0,a[i],t);
        ans+=suma(a[i]);
    }
    cout<<ans;
    return 0;
}